//#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define gcd __gcd
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
const int N = 1e5+20;
int a[N];
signed main()
{
	int sum = 0;
	int n; cin>>n;
	int cnt=1;
	for1 if((gcd(n,i))==1) cnt=(i*cnt)%n;
	if(cnt==1)
	{
		for1 if(gcd(n, i)==1) a[++sum]=i;
		cout<<sum<<endl;
		for(int i=1;i<=sum;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
	else
	{
		for2(i,1,n-2) if(gcd(n,i)==1) a[++sum]=i;
		cout<<sum<<endl;
		for(int i=1;i<=sum;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
    return 0;
}