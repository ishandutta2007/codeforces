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

vector <ll> v;

set <ll> s;

int main()
{
    ll n, M,a;
    //int m[100010]={0};
    cin>>n>>M;
    for (int i=0;i<n;i++){
        cin>>a;
        s.insert(a);
    }
    ll k=0;
    for (int i=1;M>=i;i++)
    {
        if (s.count(i)) continue;
        v.push_back(i);
        M-=i;
    }
    cout<<v.size()<<endl;
    for (int i=0;i<v.size();i++) cout<<v[i]<<' ';
    return 0;
}