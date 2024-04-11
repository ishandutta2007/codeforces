#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
set<ll> st;
ll x , y , p , res = 1e5;
bool is(ll v)
{
    if(v < y)
        return 0;
    v /= 50;
    v %= 475;
    for(int i = 0; i < 25; i++)
    {
        v = (v * 96 + 42) % 475;
        if(v + 26 == p)
            return 1;
    }
    return 0;
}
void dfs(ll v , ll k)
{
    if(st.find(v) != st.end() || k >= res || (y > v && (y - v) / 100 + k >= res))
        return;
    if(is(v))
        res = min(res , k);
    st.insert(v);
    dfs(v + 100 , k + 1);
    dfs(v - 50 , k);
}
int main()
{
    cin >> p >> x >> y;
    dfs(x , 0);
    cout << res << endl;
}