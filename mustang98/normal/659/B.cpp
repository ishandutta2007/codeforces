#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>

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
        swap(a,b);
    }
    return a;
}

vector <pair <int, string> > v[12000];

int main()
{
    string s;
    ll n, m,p,r;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        cin>>s>>r>>p;
        v[r].push_back(make_pair(p,s));
    }
    for (int i=1;i<=m;i++)
    {
        sort(v[i].begin(), v[i].end());
        if (v[i].size()==2) {
            cout<<v[i][0].second<<' '<<v[i][1].second<<endl;
            continue;
        }
        if (v[i][v[i].size()-2].first == v[i][v[i].size()-3].first)
        {
            cout<<'?'<<endl;
            continue;
        }
        else cout<<v[i][v[i].size()-1].second<<' '<<v[i][v[i].size()-2].second<<endl;
    }
    return 0;
}