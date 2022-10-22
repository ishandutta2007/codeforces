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
	vector<T> seg,seg2;
	virtual T func(T seg_a,T seg_b){
		return max(seg_a,seg_b);// function
	}

	void init(int seg_n){
		assert(seg_n>=0);
		seg.assign(4*seg_n,-2e9);
		seg2.assign(4*seg_n,0);
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
		if(seg_pos)update((seg_pos-1)/2);
	}

	T get0(){
		return seg[0];
	}

	void add(int a,int b,int r,int l,int x){
		if(a<=r){
			seg2[x]+=b;
			seg[x]+=b;
			return;
		}
		if(l<=a)return;
		int m=(r+l)/2;
		if(seg2[x]>0){
			seg[2*x+1]+=seg2[x],seg2[2*x+1]+=seg2[x];
			seg[2*x+2]+=seg2[x],seg2[2*x+2]+=seg2[x];
			seg2[x]=0;
		}
		if(m<=a){
			add(a,b,m,l,2*x+2);
		}else{
			add(a,b,r,m,2*x+1);
			add(a,b,m,l,2*x+2);
		}
		seg[x]=func(seg[2*x+1],seg[2*x+2]);
	}
	
	void add(int a,int b){
		add(a,b,0,seg_N+1,0);
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

	void print(){
		array_show(seg);
	}
};

vector<P> va,vb;
vector<tuple<int,int,int>> vc;

int main(){
	int n,m,p;
	int i,j,k;
	int a,b,c;

/*	cin>>n>>m;
	seg_tree<int> sk(m);
	for(i=0;i<n;i++){
		cin>>a>>b;
		sk.add(a,b);
		sk.print();
	}
	return 0;*/

	cin>>n>>m>>p;
	for(i=0;i<n;i++){
		cin>>a>>b;
		va.push_back(make_pair(a,b));
	}
	for(i=0;i<m;i++){
		cin>>a>>b;
		vb.push_back(make_pair(a,b));
	}
	for(i=0;i<p;i++){
		cin>>a>>b>>c;
		vc.push_back(make_tuple(a,b,c));
	}
	sort(va.begin(),va.end());
	sort(vb.begin(),vb.end());
	sort(vc.begin(),vc.end());
	seg_tree<int> st(m);
	for(i=0;i<m;i++){
		st.set(i,-vb[i].second);
	}
	int s=-2e9;
	for(i=0,k=0;i<n;i++){
		a=va[i].first;
		for(;k<p;k++){
			if(get<0>(vc[k])>=a)break;
			tie(ignore,b,c)=vc[k];
			auto itr=upper_bound(vb.begin(),vb.end(),make_pair(b+1,-1));
			int pos=distance(vb.begin(),itr);
			st.add(pos,c);
		}
		b=st.get0();
		s=max(s,-va[i].second+b);
	}
	cout<<s<<endl;
}