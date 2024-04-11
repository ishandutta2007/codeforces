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
int T,n,m;
int a[303][303];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main(){
	cin>>T;
	while(T--){
		int n,m;cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		bool can=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
//				if(a[i][j]>0){
					int cnt=0;
					for(int k=0;k<4;k++){
						int x=i+dx[k],y=j+dy[k];
						if(x>=1&&x<=n&&y>=1&&y<=m){
							cnt++;
						}
					}
					if(a[i][j]>cnt){
						can=0;
					}
					a[i][j]=cnt;
//				}
			}
		}
		if(!can){
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}