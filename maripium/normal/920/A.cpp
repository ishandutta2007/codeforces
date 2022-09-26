#include<bits/stdc++.h>
#define int long long
#define double long double
#define pb push_back
#define sp ' '
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int mod=1e9+7,N=205;
const double pi=acos(-1);
int n,k,x[N];
signed main()
{
int test;
cin>>test;
while(test--)
{
	cin>>n>>k;
	for(int i=0;i<k;++i)cin>>x[i];
    int ans=max(x[0],n-x[k-1]+1);
    //cout<<ans<<endl;
    for(int i=1;i<k;++i)ans=max(ans,(x[i]-x[i-1])/2+1);
    cout<<ans<<endl;
}
}