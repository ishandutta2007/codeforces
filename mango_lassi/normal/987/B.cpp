#include<bits/stdc++.h>  
//#pragma comment(linker, "/STACK:1024000000,1024000000")   
#pragma GCC optimize ("-ffloat-store")
#include<stdio.h>  
#include<algorithm>  
#include<queue>  
#include<string.h>  
#include<iostream>  
#include<math.h>                    
#include<stack>
#include<set>  
#include<map>  
#include<vector>  
#include<iomanip> 
#include<bitset>
#include<stdint.h>

using namespace std;         //

#define ll long long  
#define ull unsigned long long
#define pb push_back  
#define FOR(a) for(int i=1;i<=a;i++) 
#define sqr(a) (a)*(a)
#define dis(a,b) sqrt(sqr(a.x-b.x)+sqr(a.y-b.y))
ll qp(ll a,ll b,ll mod){
	ll t=1;while(b){if(b&1)t=t*a%mod;b>>=1;a=a*a%mod;}return t;
}
struct DOT{int x;int y;};
inline void read(int &x){int k=0;char f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())k=k*10+c-'0';x=k*f;} 
void ex(){puts("NO");exit(0);}
const int dx[8]={0,0,-1,1,-1,1,-1,1};
const int dy[8]={1,-1,0,0,-1,1,1,-1};
const int inf=0x3f3f3f3f; 
const ll Linf=0x3f3f3f3f3f3f3f3fLL;
const ll Mod=1e18+7;
const double eps=1e-6;
const double pi=acos(-1.0);

double x,y;

int main(){
	
	scanf("%lf%lf",&x,&y);
	double p1=1.0*y*log2(x);
	double p2=1.0*x*log2(y);
	if(fabs(p1-p2) < eps)puts("=");
	else if(p1<p2)puts("<");
	else if(p1>p2)puts(">");
}