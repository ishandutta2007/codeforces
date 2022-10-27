#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
/*
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
 
using namespace std;
 
#define ll long long
#define ld long double
#define mp make_pair
 
 
ll solve1 (string s)
{
 
    int n = s.size();
    int m = sqrt(n);
 
    vector<int> pos_one;
    for (int i = 0; i<n; i++) if (s[i]=='1') pos_one.push_back(i);
    if (pos_one.size()==0) return 0;
 
    pos_one.push_back(n);
 
 
    vector<int> cnt(n*m+n);
 
 
    ll total = 0;
    for (ll i = 1; i<=m; i++)
    {
        int cur = 0;
        cnt[i*n]++;
        for (int j = 1; j<=n; j++)
        {
            if (s[j-1]=='1') cur++;
            int idx = j - i*cur;
            total+=cnt[idx+i*n];
            cnt[idx+i*n]++;
        }
 
        cur = 0;
        cnt[i*n]--;
        for (int j = 1; j<=n; j++)
        {
            if (s[j-1]=='1') cur++;
            int idx = j - i*cur;
            cnt[idx+i*n]--;
        }
    }
 
 
    vector<int> idx(n, -1);
    int cur = 0;
    for (int i = 0; i<n; i++)
    {
        idx[i] = cur;
        if (s[i]=='1') cur++;
    }
 
    for (int i = 0; i<n; i++)
    {
        for (ll j = 1; j<=n/m&&idx[i]+j<=cur; j++)
        {
 
            ll l = pos_one[idx[i]+j-1] - i + 1;
            ll r = pos_one[idx[i]+j] - i;
            l = max(l, j*(m+1));
            if (l<=r) total+=r/j - (l-1)/j;
        }
    }
    return total;
}
 
ll solve2(string s)
{
    int n = s.size();
    vector<int> pref(n+1);
    for (int i = 1; i<=n; i++)
    {
        pref[i] = pref[i-1];
        if (s[i-1]=='1') pref[i]++;
    }
    ll cnt = 0;
    for (int i = 0; i<n; i++)
        for (int j = i+1; j<=n; j++)
        {
            if ((pref[j]>pref[i])&&((j-i)%(pref[j]-pref[i])==0)) cnt++;
        }
    return cnt;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
 
    string s;
    cin>>s;
    cout<<solve1(s);
}