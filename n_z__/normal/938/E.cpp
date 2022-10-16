#include<bits/stdc++.h>
#define int long long
using namespace std;
int v[1000001],a[1000001];
const int P=1e9+7;
main()
{
	int n;
	cin>>n;
	int c=1,i,k;
	for(i=1;i<=n;i++)c=c*i%P,cin>>a[i],v[i]=(i!=1)*(P-P/i)*v[P%i]%P+(i==1);
	sort(a+1,a+n+1);
	int ans=0;
	for(k=0;a[k+1]!=a[n];k=i-1)
	for(i=k+1;a[i]==a[k+1];++i)
	ans=(c*v[n-k]%P*a[i]+ans)%P;
	cout<<ans<<endl;
}