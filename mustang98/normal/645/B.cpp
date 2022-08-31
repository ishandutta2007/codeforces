#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
    ll n, k, ob,R=0;
    cin>>n>>k;
    ob = min (n/2, k);
    ll m=n-1;
    for (int i=0;i<ob;i++) {R+=m; m--;}
    m = 0;
    for (int i=0;i<ob;i++) {R+=m; m++;}
    R+=(n-(2*ob))*ob;
    cout<<R;
    return 0;
}