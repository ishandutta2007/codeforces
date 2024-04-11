#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
pair<double,int> d[N];int a[N];double b[N];
int main()
{
	int n,i;ll s=0;cin>>n;
	for (i=1;i<=n;i++) cin>>b[i],d[i].first=b[i],d[i].second=i,a[i]=ceil(b[i]),s+=a[i];
	for (i=1;i<=n && s;i++) if (b[i]-a[i]<0) s--,a[i]--;
	for (i=1;i<=n;i++) cout<<a[i]<<endl;
}