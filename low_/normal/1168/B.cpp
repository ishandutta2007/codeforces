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

string S;

bool check(int l, int r)
{
    for (int i=l; i<=r; i++)
    {
        for (int k=1; ; k++)
        {
            if (i+2*k>r) break;
            if (S[i]==S[i+k] && S[i+k]==S[i+2*k]) return 1;
        }
    }
    return 0;
}

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>S;
    int n=S.size();
    int ans=0;
    if (n>20) ans=(n-20)*(n-19)/2;
    for (int i=0; i<n; i++)
    {
        for (int j=i; j<min(i+20, n); j++) ans+=check(i, j);
    }
    cout<<ans;
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/