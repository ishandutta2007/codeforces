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
int mcd[26][mn];

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
    for (int i=1; i<=S.size(); i++) 
    {
        for (int c=0; c<26; c++) 
        {
            if (S[i-1]-'a'==c) mcd[c][i]=mcd[c][i-1]+1;
            else mcd[c][i]=mcd[c][i-1];
        }
    }
    int ans=0;
    for (char c='a'; c<='z'; c++) 
    {
        for (char d='a'; d<='z'; d++) 
        {
            int ret=0;
            for (int i=1; i<=S.size(); i++) if (S[i-1]==d) ret+=mcd[c-'a'][i-1];
            ans=max(ans, ret);
        }
    }

    for (int i=0; i<26; i++) ans=max(ans, mcd[i][S.size()]);
    cout<<ans;
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: ttuandung1803@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie.exe/