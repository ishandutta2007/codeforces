//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=2e9;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
int a[303][303];
int dp[606][303][303];
inline void upd(int &x,int y){
	if(y>x)x=y;
}
inline bool ok(pair<int,int>P){
	return P.first<=n&&P.second<=n;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<=600;i++)for(int j=0;j<=300;j++)for(int k=0;k<=300;k++)dp[i][j][k]=-inf;
	dp[2][1][1]=a[1][1];
	for(int i=2;i<=n+n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(j>i||k>i)continue;
				int first=max(1,i-n);
				int nfirst=max(1,i-n+1);
				int idj=j-first+1,idk=k-first+1;
				int yj=i-j,yk=i-k;
				pair<int,int>nj,nk;
				nj=make_pair(j+1,yj);
				nk=make_pair(k+1,yk);
				if((i-j)>n||(i-k)>n||(i-j)<=0||(i-k)<=0)continue;
//				cerr<<'<'<<j<<' '<<i-j<<'>';
//				cerr<<'<'<<k<<' '<<i-k<<'>';
//				cerr<<idj<<" "<<idk<<" "<<dp[i][idj][idk]<<endl;
				int nidj=nj.first-nfirst+1,nidk=nk.first-nfirst+1;
				if(ok(nj)&&ok(nk)){
					upd(dp[i+1][nidj][nidk],dp[i][idj][idk]+(nj==nk?a[nj.first][nj.second]:a[nj.first][nj.second]+a[nk.first][nk.second]));
				}
				nj=make_pair(j+1,yj);
				nk=make_pair(k,yk+1);
				nidj=nj.first-nfirst+1,nidk=nk.first-nfirst+1;
				if(ok(nj)&&ok(nk)){
					upd(dp[i+1][nidj][nidk],dp[i][idj][idk]+(nj==nk?a[nj.first][nj.second]:a[nj.first][nj.second]+a[nk.first][nk.second]));
				}
				nj=make_pair(j,yj+1);
				nk=make_pair(k+1,yk);
				nidj=nj.first-nfirst+1,nidk=nk.first-nfirst+1;
				if(ok(nj)&&ok(nk)){
					upd(dp[i+1][nidj][nidk],dp[i][idj][idk]+(nj==nk?a[nj.first][nj.second]:a[nj.first][nj.second]+a[nk.first][nk.second]));
				}
				nj=make_pair(j,yj+1);
				nk=make_pair(k,yk+1);
				nidj=nj.first-nfirst+1,nidk=nk.first-nfirst+1;
				if(ok(nj)&&ok(nk)){
					upd(dp[i+1][nidj][nidk],dp[i][idj][idk]+(nj==nk?a[nj.first][nj.second]:a[nj.first][nj.second]+a[nk.first][nk.second]));
				}
			}
		}
	}
	cout<<dp[n+n][1][1]<<endl;
	return 0;
}