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
    ll n;
    cin>>n;
    cout<<(n%2?1:2);
    return 0;
}