//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,q;
int l_to_r[500005];
int pre[500005];
int to[21][500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		int l,r;
		cin>>l>>r;l++;r++;
		l_to_r[l]=max(l_to_r[l],r);
	}
	for(int i=1;i<=5e5+1;i++)pre[i]=max(pre[i-1],l_to_r[i]);
	for(int i=1;i<=5e5+1;i++)to[0][i]=pre[i];
	for(int i=1;i<=20;i++){
		for(int j=1;j<=5e5+1;j++){
			to[i][j]=to[i-1][to[i-1][j]];
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;l++;r++;
		if(to[20][l]<r){
			cout<<"-1"<<endl;
			continue;
		}
		int tmp=l,ans=0;
		for(int i=20;i>=0;i--){
			if(to[i][tmp]<r){
				ans|=(1<<i);
				tmp=to[i][tmp];
			}
		}
		cout<<ans+1<<endl;
	}
	return 0;
}