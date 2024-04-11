#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m;
string a,b;
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>m>>a>>b;
		int flg=1,mx=48,mn=49;
		for(int i=1;i<m;i++)
			flg&=a[n-m+i]==b[i];
		for(int i=0;i<=n-m;i++)
			mx=max(mx,(int)a[i]),mn=min(mn,(int)a[i]);
		cout<<(mn<=b[0]&&b[0]<=mx&&flg?"YES\n":"NO\n");
	}
}