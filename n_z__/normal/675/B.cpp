#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    int ans=0;
    for(int x=1;x<=n;x++)
    if(1<=x+a-d&&x+a-d<=n)
    if(1<=x+b-c&&x+b-c<=n)
    if(1<=x+a+b-c-d&&x+a+b-c-d<=n)
    ans++;
    cout<<ans*n<<endl;
}