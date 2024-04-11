#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

template <typename T> class seg_tree{
private:
	static constexpr int seg_init_N=1e5+7;
	int seg_N;
	vector<T> seg;
	static T func(T seg_a,T seg_b){
		return min(seg_a,seg_b);// function
	}

	void init_reload(){
		for(int seg_i=seg_N-1;seg_i>=0;seg_i--){
			seg[seg_i]=func(seg[2*seg_i+1],seg[2*seg_i+2]);
		}
	}
	
	void update(int seg_pos){
		T seg_a=func(seg[seg_pos*2+1],seg[seg_pos*2+2]);
		if(seg[seg_pos]==seg_a)return;
		seg[seg_pos]=seg_a;
		if(seg_pos==0)return;
		update((seg_pos-1)/2);
	}

public:
	seg_tree(int seg_n){
		seg.assign(4*seg_n,INF);
		int seg_i;
		for(seg_i=0;(1<<seg_i)<seg_n;seg_i++);
		seg_N=(1<<seg_i)-1;
	}
	seg_tree(){
		this(seg_init_N);
	}
	seg_tree(T *seg_t,int seg_n){
		this(seg_n);
		for(int seg_i=0;seg_i<seg_n;seg_i++){
			seg[seg_N+seg_i]=seg_t[seg_i];
		}
		init_reload();
	}
	seg_tree(int seg_n,T seg_a){
		seg.assign(4*seg_n,0);
		int seg_i;
		for(seg_i=0;(1<<seg_i)<seg_n;seg_i++);
		seg_N=(1<<seg_i)-1;
		for(int seg_i=0;seg_i<seg_n;seg_i++){
			seg[seg_N+seg_i]=seg_a;
		}
		init_reload();
	}

	void set(int seg_pos,T seg_a){
		seg_pos+=seg_N;
		seg[seg_pos]=seg_a;
		update((seg_pos-1)/2);
	}

	T search(int seg_a,int seg_b,int seg_r,int seg_l,int seg_x){//[a,b) search
		if(seg_a<=seg_r && seg_l<=seg_b)return seg[seg_x];
		int seg_m=(seg_r+seg_l)/2;
		if(seg_b<=seg_m)return search(seg_a,seg_b,seg_r,seg_m,2*seg_x+1);
		if(seg_m<=seg_a)return search(seg_a,seg_b,seg_m,seg_l,2*seg_x+2);
		return func(search(seg_a,seg_m,seg_r,seg_m,2*seg_x+1),search(seg_m,seg_b,seg_m,seg_l,2*seg_x+2));
	}
	T search(int seg_a,int seg_b){
		return search(seg_a,seg_b,0,seg_N+1,0);
	}
};

int t[110000][5];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	vector<P> v1,v2;
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<4;j++){
			cin>>t[i][j];
		}
		v1.push_back(make_pair(t[i][1],i));
		v2.push_back(make_pair(t[i][3],i));
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	seg_tree<int> sa(n),sb(n);
	for(i=0;i<n;i++){
		j=v2[i].second;
		sa.set(i,-t[j][0]);
		sb.set(i,t[j][1]);
	}
	//cout<<"AT"<<endl;
	for(i=0;i<n;i++){
		j=v2[i].second;
		auto itr=lower_bound(v2.begin(),v2.end(),make_pair(t[j][2],-1));
		a=distance(v2.begin(),itr);
		//cout<<a<<endl;
		if(a==i)continue;
		b=sa.search(a,i);
		if(b<-t[j][1])break;
		b=sb.search(a,i);
		if(b<t[j][0])break;
	}
	//cout<<"A"<<endl;
	if(i!=n){
		cout<<"NO"<<endl;
		//cout<<"A"<<i<<endl;
		return 0;
	}
	for(i=0;i<n;i++){
		//cout<<i<<endl;
		j=v1[i].second;
		sa.set(i,-t[j][2]);
		sb.set(i,t[j][3]);
	}
	for(i=0;i<n;i++){
		//cout<<i<<endl;
		j=v1[i].second;
		auto itr=lower_bound(v1.begin(),v1.end(),make_pair(t[j][0],-1));
		a=distance(v1.begin(),itr);
		if(a==i)continue;
		b=sa.search(a,i);
		if(b<-t[j][3])break;
		b=sb.search(a,i);
		if(b<t[j][2])break;
	}
	if(i!=n)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}