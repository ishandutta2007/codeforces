#include<bits/stdc++.h>
using namespace std;
int const N=2333;
int n,a[N],ans[N][N];
pair<int,int>p[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],p[i]={a[i],i};
	sort(p+1,p+1+n);
	for(int i=1;i<=n;i++)
		for(int j=i;a[p[i].second]--;j=(j+n)%(n+1))
			ans[j][p[i].second]=1;
	cout<<n+1<<"\n";
	for(int i=0;i<=n;i++,cout<<"\n")
		for(int j=1;j<=n;j++)
			cout<<ans[i][j];
}