#include <bits/stdc++.h>
using namespace std;
int v[100001];
int main()
{
#ifdef HOME
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
#endif // HOME
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,l=0,sus=0,x,i;
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>v[i];
    sort(v+1,v+n+1);
    for(i=n;i>n-(n+1)/2;i--)
      l+=v[i];
    for(;i>=1;i--)
      sus+=v[i];
    cout<<1LL*l*l+1LL*sus*sus;
    return 0;
}