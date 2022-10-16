#include<bits/stdc++.h>
#define int long long
const int N=1050;
using namespace std;


int n,m;
int a[N][N];
int mx[N][N],mn[N][N];

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>a[i][j];	
			mx[i][j]=-1e8;
			if(i==1&&j==1){
				mx[i][j]=mn[i][j]=a[i][j];
				continue;
			}
			mx[i][j]=-1e8;
			if(i>1)mx[i][j]=max(mx[i][j],mx[i-1][j]+a[i][j]);
			if(j>1)mx[i][j]=max(mx[i][j],mx[i][j-1]+a[i][j]);
			mn[i][j]=1e8;
			if(i>1)mn[i][j]=min(mn[i][j],mn[i-1][j]+a[i][j]);
			if(j>1)mn[i][j]=min(mn[i][j],mn[i][j-1]+a[i][j]);
		}
	if((n+m+1)&1){
		cout<<"NO"<<endl;
		return ;
	}
	if(mn[n][m]<=0&&mx[n][m]>=0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}