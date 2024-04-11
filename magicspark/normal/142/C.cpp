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
int n,m,nx,ny,vv;
short dp[8][9][1<<19];
char prv[8][9][1<<19];
int pmask[8][9][1<<19];
#define func \
	short &val=dp[nx][ny][nmask];\
	char &pos=prv[nx][ny][nmask];\
	int &pmsk=pmask[nx][ny][nmask];\
	if(val<dp[i][j][mask]+1){\
		val=dp[i][j][mask]+1;\
		pos=vv;\
		pmsk=mask;\
	}
char ans[55][55];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ans[i][j]='.';
		}
	}
	if(n<=2||m<=2){
		puts("0");
		for(int i=0;i<n;i++){
			for(int i=0;i<m;i++)cout<<".";
			cout<<endl;
		}
		return 0;
	}
	memset(dp,-1,sizeof dp);
	memset(prv,-1,sizeof prv);
	dp[0][0][0]=0;
	for(int i=0;i+2<n;i++){
		for(int j=0;j<m;j++){
			nx=i;ny=j+1;
			if(ny==m)nx++,ny=0;
			for(int mask=0;mask<(1<<m+m+1);mask++){
				if(i+2<n&&j+2<m){
					bool can=1;vv=1;
					if(mask&7)can=0;
					if(mask&(1<<m+1))can=0;
					if(can){
						int nmask=(mask|7|(1<<m+1)|(1<<m+m+1))/2;
						func
					}
				}
				if(j>=2&&i+2<n){
					bool can=1;vv=2;
					if(mask&1)can=0;
					if(mask&(7*(1<<m-2)))can=0;
					if(mask&(1<<m*2))can=0;
					if(can){
						int nmask=(mask|1|(7*(1<<m-2))|(1<<m*2))/2;
						func
					}
				}
				if(j>=1&&j+1<m&&i+2<n){
					bool can=1;vv=3;
					if(mask&1)can=0;
					if(mask&(1<<m))can=0;
					if(mask&(1<<m+m))can=0;
					if(mask&(1<<m+m-1))can=0;
					if(can){
						int nmask=(mask|1|(1<<m)|(7*(1<<m+m-1)))/2;
						func
					}
				}
				if(j+2<m&&i+2<n){
					bool can=1;vv=4;
					if(mask&1)can=0;
					if(mask&(7*(1<<m)))can=0;
					if(mask&(1<<(m+m)))can=0;
					if(can){
						int nmask=(mask|1|(7*(1<<m))|(1<<m+m))/2;
						func
					}
				}
				if(dp[nx][ny][mask/2]<dp[i][j][mask]){
					dp[nx][ny][mask/2]=dp[i][j][mask];
					prv[nx][ny][mask/2]=0;pmask[nx][ny][mask/2]=mask;
				}
			}
		}
	}
	short fans=0;int pos;
	for(int i=0;i<(1<<m+m+1);i++)fans=max(fans,dp[n-2][0][i]);
	for(int i=0;i<(1<<m+m+1);i++)if(fans==dp[n-2][0][i])pos=i;
	cout<<fans<<endl;
	int x=n-2,y=0,mask=pos;
	char cur='A';
	while(x>=0){
		int type=prv[x][y][mask];
		mask=pmask[x][y][mask];
		y--;if(y<0)y=m-1,x--;
		if(type==1){
			ans[x][y]=cur;
			ans[x][y+1]=cur;
			ans[x][y+2]=cur;
			ans[x+1][y+1]=cur;
			ans[x+2][y+1]=cur;
			cur++;
		}
		if(type==2){
			ans[x][y]=cur;
			ans[x+1][y-2]=cur;
			ans[x+1][y-1]=cur;
			ans[x+1][y]=cur;
			ans[x+2][y]=cur;
			cur++;
		}
		if(type==3){
			ans[x][y]=cur;
			ans[x+1][y]=cur;
			ans[x+2][y]=cur;
			ans[x+2][y-1]=cur;
			ans[x+2][y+1]=cur;
			cur++;
		}
		if(type==4){
			ans[x][y]=cur;
			ans[x+1][y]=cur;
			ans[x+2][y]=cur;
			ans[x+1][y+1]=cur;
			ans[x+1][y+2]=cur;
			cur++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
}