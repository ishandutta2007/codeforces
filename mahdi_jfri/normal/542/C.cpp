#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e2 + 20;
ll f[maxn] , _max , ans = 1;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> f[i] , f[i]--;
    for(int i = 0; i < n; i++)
    {
        set<int> st;
        int k = i;
        while(st.find(k) == st.end())
        {
            st.insert(k);
            k = f[k];
        }
        int t = 0;
        while(st.find(k) != st.end())
        {
            t++;
            st.erase(k);
            k = f[k];
        }
        _max = max(_max , (ll)st.size());
        ans = ans * t / __gcd(ans , (ll)t);
    }
    cout << _max / ans * ans + ((_max % ans || !_max)? ans : 0);
}