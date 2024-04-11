#include <iostream>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;

set <ll> m;
vector <pair <int, int> > v;

int main()
{
    ll n,a,l=1,r;
    cin>>n;
    for (ll i=0;i<n;i++)
    {
        cin>>a;
        if (m.count(a))
        {
            r=i+1;
            v.push_back(make_pair(l,r));
            m.clear();
            l=i+2;
        }
        else
        {
            m.insert(a);
        }
    }
    if (!m.empty())
    {
        if (v.empty()) {cout<<-1; return 0;}
        else v[v.size()-1].second=n;
    }
    cout<<v.size()<<endl;
    for (int i=0;i<v.size();i++) cout<<v[i].first<<' '<<v[i].second<<endl;
    return 0;
}