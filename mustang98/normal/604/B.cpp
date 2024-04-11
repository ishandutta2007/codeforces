#include <iostream>
#include <vector>

using namespace std;
typedef long long int ll;

vector <ll> m;

int main()
{
    ll n, k, kolp, a, rez=0;
    cin>>n>>k;
    for (int i=0;i<n;i++)
    {
        cin>>a;
        m.push_back(a);
    }
    rez=m[m.size()-1];
    kolp=n-k;
    if (kolp<=0) {cout<<rez; return 0;};
    for (int i=0; i<kolp;i++) rez=max(rez, m[i]+m[kolp*2-i-1]);
    cout<<rez;
    return 0;
}