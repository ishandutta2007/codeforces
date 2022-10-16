/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
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
int n,m;
int x[100005],y[100005];
int a[100005],b[100005];
set<pair<int,int> >X,Y;
set<pair<int,int> >ban;
set<pair<pair<int,int>,int> >range;
const char lxr[]="LOSE";
const char djq[]="WIN";
map<pair<int,int>,int>id;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		X.insert(make_pair(x[i],y[i]));
		Y.insert(make_pair(y[i],x[i]));
		ban.insert(make_pair(x[i],y[i]));
		id[make_pair(x[i],y[i])]=i;
	}
	int cx=0,cy=0;
	while(1){
//		cerr<<"step: "<<cx<<" "<<cy<<endl;
		if(ban.count(make_pair(cx,cy))){
			range.insert(make_pair(make_pair(cx,cy),0));
			cx++;cy++;continue;
		}
		while(X.size()&&X.begin()->first<cx)X.erase(X.begin());
		while(Y.size()&&Y.begin()->first<cy)Y.erase(Y.begin());
		int idx=X.size()?id[*X.begin()]:0;
		int idy=Y.size()?id[make_pair(Y.begin()->second,Y.begin()->first)]:0;
		if(!idx&&!idy)break;
		int len=min(idx==0?inf:x[idx]-cx,idy==0?inf:y[idy]-cy);
		len=max(len,0);
		if(len){
			range.insert(make_pair(make_pair(cx,cy),len-1));
			cx+=len;cy+=len;
		}
		int addx=idx&&x[idx]==cx&&y[idx]<=cy,addy=idy&&y[idy]==cy&&x[idy]<=cx;
//		cerr<<cx<<" "<<cy<<" "<<addx<<" "<<addy<<" "<<x[idx]<<" "<<y[idx]<<endl;
		if(!addx&&!addy){
			range.insert(make_pair(make_pair(cx,cy),0));
			cx++;cy++;
		}
		if(addx)cx++;
		if(addy)cy++; 
	}
	range.insert(make_pair(make_pair(cx,cy),inf));
	/*
	for(auto P:range){
		cerr<<"range: "<<P.first.first<<" "<<P.first.second<<" "<<P.second<<endl;
	}
	*/
	while(m--){
		int a,b;cin>>a>>b;
		if(ban.count(make_pair(a,b))){
			puts(lxr);continue;
		}
		auto itr=range.upper_bound(make_pair(make_pair(a,b),inf));
		if(itr==range.begin())puts(djq);
		else{
			itr--;
			int sx=itr->first.first,sy=itr->first.second,len=itr->second;
			if(a-sx==b-sy&&a-sx<=len)puts(lxr);
			else puts(djq);
		}
	}
	return 0;
}