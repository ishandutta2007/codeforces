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
#include<cassert>
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
	virtual T func(T seg_a,T seg_b){
		return max(seg_a,seg_b);// function
	}

	void init(int seg_n){
		assert(seg_n>=0);
		seg.assign(4*seg_n,0);
		int seg_i;
		for(seg_i=0;(1<<seg_i)<seg_n;seg_i++);
		seg_N=(1<<seg_i)-1;
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
		init(seg_n);
	}
	seg_tree(){
		init(seg_init_N);
	}
	seg_tree(T *seg_t,int seg_n){
		init(seg_n);
		for(int seg_i=0;seg_i<seg_n;seg_i++){
			seg[seg_N+seg_i]=seg_t[seg_i];
		}
		init_reload();
	}
	seg_tree(vector<T> &seg_t,int seg_n){
		init(seg_n);
		for(int seg_i=0;seg_i<seg_n;seg_i++){
			seg[seg_N+seg_i]=seg_t[seg_i];
		}
		init_reload();
	}
	seg_tree(T seg_a,int seg_n){
		init(seg_n);
		for(int seg_i=0;seg_i<seg_n;seg_i++){
			seg[seg_N+seg_i]=seg_a;
		}
		init_reload();
	}

	void set(int seg_pos,T seg_a){
		assert(seg_pos>=0 && seg_pos<=seg_N);
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

int bef[330000];
int t[330000];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c,d,e;
	LL s=0;
	cin>>n;
	vector<int> v1;
	vector<P> v2;
	seg_tree<int> sa(-1,n);
	memset(bef,-1,sizeof(bef));
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(bef[a]);
		bef[a]=i;
		v2.push_back(make_pair(a,i));
		t[i]=a;
	}
	seg_tree<int> sb(v1,n);
	sort(v2.rbegin(),v2.rend());
	for(i=0;i<n;i++){
		a=v2[i].first,b=v2[i].second;
		if(b==0)c=0;
		else c=sa.search(0,b)+1;
		c=max(c,b-a+1);
		d=sa.search(0,c+a);
		sa.set(b,b);
		if(d>=c || c+a>n)continue;

		d=sb.search(c,c+a);
		if(d<c){
			//cout<<c<<" "<<c+a<<endl;
			s++;
		}
		while(c+a<n && t[c+a]<a && c<b){
			d=max(d,v1[c+a]);
			c++;
			if(d<c){
				//cout<<c<<" "<<c+a<<endl;
				s++;
			}
		}
	}
	cout<<s<<endl;
}