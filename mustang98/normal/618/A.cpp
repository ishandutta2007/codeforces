#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    if (a<b) swap(a,b);
    while (b)
    {
        a%=b;
        swap (a,b);
    }
    return a;
}

int main()
{
    ll n, a, b;
    vector <int> m;
    //cin>>n;
    //for (int i=0; i<n; i++) cin>>m[i];
    cin>>n;
    for (int i=0;i<n;i++)
    {
        m.push_back(1);
        while(m.size()>1 && m[m.size()-1] == m[m.size()-2])
        {
            m[m.size()-2]+=1;
            m.pop_back();
        }
    }
    for (int i=0;i<m.size();i++) cout<<m[i]<<' ';
    return 0;
}