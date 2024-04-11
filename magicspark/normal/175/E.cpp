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
int a,b,c;
double ra,rb,rc;
int da,db;
double la,lb,lc;
double ans;
int f[22],g[22],szf,szg;
double calc_all(){
	vector<pair<double,double> >vec;
	for(int i=1;i<=szf;i++){
		if(f[i]==2)vec.push_back(make_pair((double)i-lc,(double)i+lc));
	}
	for(int i=1;i<=szg;i++){
		if(g[i]==2)vec.push_back(make_pair((double)i-lc,(double)i+lc));
	}
	double ret=0;
	for(int i=1;i<=szf;i++){
		if(f[i]==0){
			double L=(double)i-la,R=(double)i+la;
			double mul=R-L;
			for(auto p:vec){
				mul+=max(0.0,min(R,p.second)-max(L,p.first));
			}
			ret+=mul*da;
		}
		if(f[i]==1){
			double L=(double)i-lb,R=(double)i+lb;
			double mul=R-L;
			for(auto p:vec){
				mul+=max(0.0,min(R,p.second)-max(L,p.first));
			}
			ret+=mul*db;
		}
	}
	for(int i=1;i<=szg;i++){
		if(g[i]==0){
			double L=(double)i-la,R=(double)i+la;
			double mul=R-L;
			for(auto p:vec){
				mul+=max(0.0,min(R,p.second)-max(L,p.first));
			}
			ret+=mul*da;
		}
		if(g[i]==1){
			double L=(double)i-lb,R=(double)i+lb;
			double mul=R-L;
			for(auto p:vec){
				mul+=max(0.0,min(R,p.second)-max(L,p.first));
			}
			ret+=mul*db;
		}
	}
	return ret;
}
void dfs_g(int x,int A,int B,int C){
	if(x==szg+1){
		ans=max(ans,calc_all());
		return;
	}
	if(A&&f[x]==0){g[x]=0;dfs_g(x+1,A-1,B,C);}
	if(B&&f[x]<=1){g[x]=1;dfs_g(x+1,A,B-1,C);}
	if(C){g[x]=2;dfs_g(x+1,A,B,C-1);}
}
void dfs_f(int x,int A,int B,int C){
	if(x==szf+1){
		dfs_g(1,A,B,C);
		return;
	}
	if(A){f[x]=0;dfs_f(x+1,A-1,B,C);}
	if(B){f[x]=1;dfs_f(x+1,A,B-1,C);}
	if(C){f[x]=2;dfs_f(x+1,A,B,C-1);}
}
int main(){
	cin>>a>>b>>c;
	cin>>ra>>rb>>rc;
	cin>>da>>db;
	la=sqrt(ra*ra-1);lb=sqrt(rb*rb-1);lc=sqrt(rc*rc-1);
	szf=(a+b+c)/2;szg=a+b+c-szf;
	dfs_f(1,a,b,c);
	printf("%.12lf\n",ans);
	return 0;
}