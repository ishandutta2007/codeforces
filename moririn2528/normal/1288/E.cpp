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
	vector<vector<T> > seg;

	void init(int seg_n){
		assert(seg_n>=0);
		seg.assign(4*seg_n,(vector<T>){});
		int seg_i;
		for(seg_i=0;(1<<seg_i)<seg_n;seg_i++);
		seg_N=(1<<seg_i)-1;
	}

	void init_reload(){
		for(int seg_i=seg_N-1;seg_i>=0;seg_i--){
			seg[seg_i]=seg[2*seg_i+1];
			seg[seg_i].insert(seg[seg_i].end(),seg[2*seg_i+2].begin(),seg[2*seg_i+2].end());
			sort(seg[seg_i].begin(),seg[seg_i].end());
		}
	}

public:
	seg_tree(vector<T> &seg_t){
		int seg_n=seg_t.size();
		init(seg_n);
		for(int seg_i=0;seg_i<seg_n;seg_i++){
			seg[seg_N+seg_i].push_back(seg_t[seg_i]);
		}
		init_reload();
	}

	T search(int seg_a,int seg_b,int p,int seg_r,int seg_l,int seg_x){//[a,b) search
		if(seg_a<=seg_r && seg_l<=seg_b){
			auto itr=lower_bound(seg[seg_x].begin(),seg[seg_x].end(),p);
			return distance(seg[seg_x].begin(),itr);
		}
		int seg_m=(seg_r+seg_l)/2;
		if(seg_b<=seg_m)return search(seg_a,seg_b,p,seg_r,seg_m,2*seg_x+1);
		if(seg_m<=seg_a)return search(seg_a,seg_b,p,seg_m,seg_l,2*seg_x+2);
		return search(seg_a,seg_b,p,seg_r,seg_m,2*seg_x+1)+search(seg_a,seg_b,p,seg_m,seg_l,2*seg_x+2);
	}
	T search(int seg_a,int seg_b,int p){
		return search(seg_a,seg_b,p,0,seg_N+1,0);
	}
};

vector<int> v1[330000],v2;

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n>>m;
	for(i=0;i<n;i++)v1[i].push_back(-i-1);
	
	for(i=0;i<m;i++){
		cin>>a;
		a--;
		v2.push_back(v1[a].back());
		v1[a].push_back(i);
	}
	//array_show(v2);
	seg_tree<int> sa(v2);
	for(i=0;i<n;i++){
		v1[i].push_back(m);
		c=0;
		//cout<<"WA"<<endl;//////////////////////////////////
		for(j=1;j<v1[i].size();j++){
			//cout<<j<<endl;///////////////////////////////////////
			b=v1[i][j-1];
			a=max(b,0);
			//cout<<a<<" "<<v1[i][j]<<" "<<b<<endl;
			a=sa.search(a,v1[i][j],b);
			//cout<<a<<endl;
			if(j==1)a+=i+1;
			c=max(c,a);
		}
		if(v1[i].size()==2)a=i+1;
		else a=1;
		cout<<a<<" "<<c<<endl;
	}
}