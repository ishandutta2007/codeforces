#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll p(int b)
{
    ll rez=1;
    for(int i=0;i<b;i++) rez*=2;
    return rez;
}

int main()
{
    ll n,R=0;
    cin>>n;
    for(int i=1;i<=n;i++) R+=p(i);
    cout<<R;
    return 0;
}