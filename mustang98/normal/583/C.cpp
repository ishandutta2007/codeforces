#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

multiset <ll> m;
multiset <ll>::iterator it, it1;
vector <ll> a;

ll gcd(ll a, ll b)
{
    if (a<b) swap(a,b);
    while (b)
    {
        a%=b;
        if (a<b) swap(a,b);
    }
    return a;
}

int main()
{
    ll nod,n,b;
    cin>>n;
    for (int i=0;i<n*n;i++)
    {
        cin>>b;
        m.insert(b);
    }
    it=m.end();
    it--;
    a.push_back(*it);
    m.erase(it);

    while (a.size()<n)
    {
        it=m.end();
        it--;
        b=*it;
        //a.push_back(*it);
        m.erase(it);
        for (int i=0;i<a.size();i++)
        {
            nod=gcd(b,a[i]);
            it1=m.find(nod);
            m.erase(it1);
            it1=m.find(nod);
            m.erase(it1);
        }
        a.push_back(b);
    }
    for (int i=0; i<a.size(); i++) cout<<a[i]<<' ';
    return 0;
}