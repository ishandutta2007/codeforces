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

string A, B;
vector <pii> VA, VB;

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while (T--)
    {
        cin>>A>>B;
        VA={{A[0], 1}}; VB={{B[0], 1}};
        for (int i=1; i<A.size(); i++)
        {
            if (A[i]==A[i-1]) VA.back().YY++;
            else VA.push_back({A[i], 1});
        }
        for (int i=1; i<B.size(); i++)
        {
            if (B[i]==B[i-1]) VB.back().YY++;
            else VB.push_back({B[i], 1});
        }

        if (VA.size()!=VB.size())
        {
            cout<<"NO\n";
            continue;
        }

        bool c=1;
        for (int i=0; i<VA.size(); i++) 
        {
            if (VA[i].XX!=VB[i].XX) 
            {
                c=0;
                break;
            }
            else if (VA[i].YY>VB[i].YY)
            {
                c=0;
                break;
            }
        }

        if (c) cout<<"YES\n";
        else cout<<"NO\n";
        
    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/