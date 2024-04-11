#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a,b,c;
ll ans;

int main()
{
    cin>>a>>b;
    if (a<b)    swap(a,b);
    while (b)
    {
        ans+=a/b;
        c=a%b;
        a=b;
        b=c;
    }
    cout<<ans<<endl;
    return 0;
}