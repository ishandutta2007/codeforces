#include<bits/stdc++.h>
#define int long long
const int N=1000005;
const int M=50,mod=998244353;
using namespace std;

int d,n,m;
int a[N],b[N];
int xs[M][M],mul[M][M];

void solve(){
	cin>>d>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	sort(b+1,b+1+m);
	b[0]=-N;
	b[m+1]=N*2;
	for(int i=0;i<=m+1;i++)
		for(int j=0;j<=m+1;j++)
			mul[i][j]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m+1;j++){
			for(int k=j+1;k<=m+1;k++){
				if(a[i]>b[j]&&a[i]<b[k]){
					int L=min(a[i]-b[j],d);
					int R=min(b[k]-a[i],d);
					mul[j][k]=mul[j][k]*min(L,R)%mod;
				}
			}
		}
	}
	for(int i=1;i<1<<m;i++){
		int res=1,pr=0;
		for(int j=1;j<=m;j++){
			if(i>>(j-1)&1){
				res=-res;
				res=res*mul[pr][j]%mod;
				pr=j;
			}
		}
		res=res*mul[pr][m+1]%mod;
		pr=0;
		for(int j=1;j<=m;j++){
			if(i>>(j-1)&1){
				xs[pr][j]+=res;
				pr=j;
			}
		}
		xs[pr][m+1]+=res;
	}
	for(int i=0;i<=m+1;i++)
		for(int j=0;j<=m+1;j++)
			xs[i][j]%=mod;
	int q;cin>>q;
	int all=1;
	for(int i=1;i<=n+1;i++)all=all*(d+1)%mod;
	while(q--){
		int x;cin>>x;
		int res=0;
		for(int j=0;j<=m+1;j++){
			for(int k=j+1;k<=m+1;k++){
				if(x>b[j]&&x<b[k]){
					int L=min(x-b[j],d);
					int R=min(b[k]-x,d);
					res+=xs[j][k]*min(L,R)%mod;
				}
			}
		}
		res=all+res;
		cout<<(res%mod+mod)%mod<<'\n';
	}
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;//cin>>_T;
	while(_T--)solve();
}