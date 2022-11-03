#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll maxn = 1e6 + 20;
ll l[maxn] , r[maxn] , a[maxn] , res , x[maxn];
vector<ll> st;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && a[st.back()] <= a[i])
            st.pop_back();
        if(!st.empty())
            l[i] = st.back();
        else
            l[i] = -1;
        st.pb(i);
    }
    st.clear();
    for(int i = n - 1; i > -1; i--)
    {
        while(!st.empty() && a[st.back()] < a[i])
            st.pop_back();
        if(!st.empty())
            r[i] = st.back();
        else
            r[i] = n;
        st.pb(i);
    }
    for(int i = 0; i < n; i++)
    {
        r[i]--;
        l[i]++;
        x[i] = (r[i] - i + 1) * (i - l[i] + 1);
    }
    st.clear();
    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && a[st.back()] >= a[i])
            st.pop_back();
        if(!st.empty())
            l[i] = st.back();
        else
            l[i] = -1;
        st.pb(i);
    }
    st.clear();
    for(int i = n - 1; i > -1; i--)
    {
        while(!st.empty() && a[st.back()] > a[i])
            st.pop_back();
        if(!st.empty())
            r[i] = st.back();
        else
            r[i] = n;
        st.pb(i);
    }
    for(int i = 0; i < n; i++)
    {
        r[i]--;
        l[i]++;
        res -= (a[i] * ((r[i] - i + 1) * (i - l[i] + 1) - x[i]));
    }
    cout << res << endl;
}