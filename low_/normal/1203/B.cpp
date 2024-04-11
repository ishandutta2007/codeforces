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
        deque <int> A, pe={}, areas={};
        cin>>n;
        A.assign(n*4, 0);
        for (int i=0; i<n*4; i++) cin>>A[i];
        sort(A.begin(), A.end());

        bool b=1;
        for (int i=1; i<n*4; i+=2) 
        {
            if (A[i]!=A[i-1]) b=0;
            else pe.push_back(A[i]);
        }
        if (b==0) 
        {
            cout<<"NO\n";
            continue;
        }

        while (!pe.empty())
        {
            areas.push_back(pe.front()*pe.back());
            pe.pop_back();
            pe.pop_front();
        }
        for (int i=1; i<n; i++) if (areas[i]!=areas[0]) b=0;
        if (b==0) cout<<"NO\n";
        else cout<<"YES\n";
    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/