#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
vector<ll> a;
set<ll> st;
ll last;
//ll abs(ll a)
//{
  //  return (a < 0? -a : a);
//}
int main()
{
    ll b1 , q , l , m;
    cin >> b1 >> q >> l >> m;
    for(int i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        st.insert(x);
    }
    if(abs(b1) > l)
    {
        cout << 0;
        return 0;
    }
    if(b1 == 0)
    {
        if(st.find(0) == st.end())
        {
            cout << "inf";
            return 0;
        }
        cout << 0;
        return 0;
    }
    if(q == 1)
    {
        if(st.find(b1) == st.end() && abs(b1) <= l)
        {
            cout << "inf";
            return 0;
        }
        cout << 0;
        return 0;
    }
    if(q == 0)
    {
        if(st.find(0) == st.end())
        {
            cout << "inf";
            return 0;
        }
        if(st.find(b1) == st.end() && abs(b1) <= l)
        {
            cout << 1;
            return 0;
        }
        cout << 0;
        return 0;
    }
    if(q == -1)
    {
        if((st.find(b1) == st.end() || st.find(-b1) == st.end()) && abs(b1) <= l)
        {
            cout << "inf";
            return 0;
        }
        cout << 0;
        return 0;
    }
    last = b1;
    ll res = 0;
    while(abs(last) <= l)
    {
        if(st.find(last) == st.end())
            res++;
        last *= q;
    }
    cout << res;
}