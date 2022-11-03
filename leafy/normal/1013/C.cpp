#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=200005;
int n;
ll a[N];
ll ans;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=2*n;i++) cin>>a[i];
    sort(a+1,a+2*n+1);
    ans=(a[2*n]-a[n+1])*(a[n]-a[1]);
    for(int i=2;i<=n;i++) ans=min(ans,(a[2*n]-a[1])*(a[i+n-1]-a[i]));
    cout<<ans;
    return 0;
}