/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
bitset<500005>bs[1005];
int n,m;
int a[1005],b[1005];
pair<vector<int>,vector<int> >solve(int *f,int len){
	int sum=0;
	for(int i=1;i<=len;i++)sum+=f[i];
	bs[0].reset();bs[0].set(0);
	for(int i=1;i<=len;i++){
		bs[i]=bs[i-1]|(bs[i-1]<<f[i]);
	}
	bool can=0;
	for(int i=0;i<=5e5;i++){
		if(i*2==sum&&bs[len][i])can=1;
	}
	if(!can)return {{},{}};
	int pos=len,val=sum/2;
	vector<int>v1,v2;
	for(int _=0;_<len;_++){
		if(bs[pos-1][val]){
			v1.push_back(f[pos]);
		}else{
			v2.push_back(f[pos]);
			val=val-f[pos];
		}
		pos--;
	}
	if(v1.size()>v2.size())swap(v1,v2);
	return make_pair(v1,v2);
}
int curx,cury;
void add(int x,int y){
	curx+=x;
	cout<<curx<<" "<<cury<<endl;
	cury+=y;
	cout<<curx<<" "<<cury<<endl;
}
int main(){
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		cin>>m;
		for(int i=1;i<=m;i++)cin>>b[i];
		auto A=solve(a,n);
		auto B=solve(b,m);
		if(!A.first.size()||!A.second.size()||!B.first.size()||!B.second.size()||n!=m){
			puts("No");continue;
		}
		curx=cury=0;
		puts("Yes");
		sort(A.first.rbegin(),A.first.rend());
		sort(A.second.rbegin(),A.second.rend());
		sort(B.first.begin(),B.first.end());
		sort(B.second.begin(),B.second.end());
		int sz=B.second.size()-A.first.size();
		for(int i=0;i<A.first.size();i++){
			add(A.first[i],B.second[i]);
		}
		int pos=0;
		for(int i=A.first.size();i<B.second.size();i++){
			add(-A.second[pos++],B.second[i]);
		}
		for(int i=0;i<B.first.size();i++){
			add(-A.second[pos++],-B.first[i]);
		}
	}
	return 0;
}