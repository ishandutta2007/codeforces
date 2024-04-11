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

template<typename T> class bit{
private:
	vector<T> bit_vec;
	int bit_N=20;

	T bit_comp(T a,T b){
		return a+b;
	}

public:

	bit(int n){
		for(bit_N=0;bit_N<30;bit_N++){
			if(n<(1<<bit_N))break;
		}
		bit_vec.assign((1<<bit_N),0);
	}

	void set(int pos,T x){
		bit_vec[pos]=bit_comp(bit_vec[pos],x);
		for(int i=0;i<bit_N;i++){
			if(pos&(1<<i))continue;
			pos|=(1<<i);
			bit_vec[pos]=bit_comp(bit_vec[pos],x);
		}
	}

	T search(int pos){
		T s=bit_vec[pos];
		for(int i=0;pos>=(1<<i);i++){
			if(pos&(1<<i))continue;
			pos-=(1<<i);
			s=bit_comp(s,bit_vec[pos]);
		}
		return s;
	}
};

void init(){
	
}

void solve(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n>>m;
	vector<int> v1(n),v2(m);
	for(i=0;i<n;i++){
		cin>>a;
		a--;
		v1[a]=i;
	}
	for(i=0;i<m;i++){
		cin>>a;
		a--;
		v2[i]=v1[a];
	}
	bit<int> bt(n);
	a=-1;
	LL s=0;
	for(i=0;i<m;i++){
		if(a<v2[i]){
			a=v2[i];
			s+=2*(v2[i]-bt.search(v2[i]))+1;
		}else s++;
		bt.set(v2[i],1);
	}
	cout<<s<<endl;
}

int main(){
	int n,i;
	init();
	cin>>n;
	for(i=0;i<n;i++){
		solve();
	}
}