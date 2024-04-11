#include<bits/stdc++.h>
#define ll long long
#define N 300010
using namespace std;
ll a[N],ans,t;
int main()
{
	int n,i;cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=n;i;i--){t+=a[i]/2;if (a[i]&1 && t>0) ans++,t--;}
	ans+=t*2/3;cout<<ans;
}