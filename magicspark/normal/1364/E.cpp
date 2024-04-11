/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int n,ans[]={1,0,2};
vector<int>vec;
int mem[2222][2222];
int ask(int x,int y){
	if(mem[x][y])return mem[x][y];
	if(mem[y][x])return mem[y][x];
	
//	if(x==y||x>=n||y>=n||x<0||y<0)while(1);
	#ifdef LOCAL
	return ans[x]|ans[y];
	#else
	cout<<"? "<<x+1<<" "<<y+1<<endl;
	fflush(stdout);
	int ret;cin>>ret;return mem[x][y]=ret;
	#endif
}
int f(int x){
	return 11-__builtin_popcount(x);
}
bool cmp(pair<int,int>a,pair<int,int>b){
	return f(a.first)>f(b.first);
}
int hv[2222];
vector<pair<int,int> >v;
int get_val(int x){
	int ret=2047;
	for(int i=0;i<20;i++){
		int pos=rand()%n;
		while(pos==x)pos=rand()%n;
		ret&=ask(pos,x);
	}
	return ret;
}
int res[2222],base[11];
int check(int id,int len,int x){
	int got=ask(id,x);
	if(got&((1<<len)-1))return -1;
	for(int j=len;(1<<j)<n;j++){
		if(ask(x,base[j])&(1<<j))return j;
	}
	return inf;
}
int main(){
	srand(time(0));
	cin>>n;
	for(int i=1;i<=n;i++)vec.push_back(i-1);
	random_shuffle(vec.begin(),vec.end());
	memset(base,-1,sizeof base);
	memset(res,-1,sizeof res);
	while(1){
		int tmp=rand()%n;
		if(hv[tmp])continue;
		hv[tmp]=1;
		int val=get_val(tmp);
		res[tmp]=val;
		for(int j=0;j<11;j++)if(!(val&(1<<j)))base[j]=tmp;
		int all=1;
//		cerr<<"show: "<<tmp<<" "<<val<<endl;
		for(int j=0;(1<<j)<n;j++){
			if(base[j]==-1)all=0;
		}
		if(all)break;
	}
	int pos=-1,best=1,id=base[0];
	for(int i=0;i<vec.size();i++){
		int tmp=vec[i];
		if(res[tmp]>0)continue;
		if(res[tmp]==0){
			pos=tmp;break;
		}
		int got=check(id,best,vec[i]);
		if(got==inf){
			pos=vec[i];
			break;
		}
		if(got>best){
			best=got;
			id=vec[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(i-1!=pos)res[i]=ask(pos,i-1);
		else res[i]=0;
	}
//	cerr<<pos<<endl;
	cout<<"! ";
	for(int i=1;i<=n;i++)cout<<res[i]<<" ";
	cout<<endl;
	return 0;
}