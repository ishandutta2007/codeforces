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
        int A[3];
        cin>>A[0]>>A[1]>>A[2];
        sort(A, A+3);

        if (A[0]>=4) cout<<7;
        else if (A[0]>=3) cout<<6;
        else if (A[0]>=2 && A[2]>=3) cout<<5;
        else if (A[0]>=1 && A[1]>=2) cout<<4;
        else if (A[0]>=1) cout<<3;
        else 
        {
            if (A[1]>=2) cout<<3;
            else if (A[1]>=1) cout<<2;
            else if (A[2]>=1) cout<<1;
            else cout<<0;
        }
        cout<<"\n";

    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: ttuandung1803@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie.exe/