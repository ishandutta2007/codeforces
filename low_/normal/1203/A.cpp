#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int q, n;

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    while (q--)
    {
        cin>>n;
        deque <int> A, cw={};
        A.assign(n, 0);
        for (int i=0; i<n; i++) cin>>A[i], cw.push_back(i+1);
        bool b=0;
        for (int i=0; i<n; i++)
        {
            if (A==cw) b=1;
            cw.push_back(cw.front());
            cw.pop_front();
        }
        reverse(cw.begin(), cw.end());
        for (int i=0; i<n; i++)
        {
            if (A==cw) b=1;
            cw.push_back(cw.front());
            cw.pop_front();
        }
        if (b==1) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/