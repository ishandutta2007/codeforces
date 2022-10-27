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
#define mn 200005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

vector <int> letterPos[26];
string s;
int letterCnt[mn][26];

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n>>s;
    for (int i=0; i<26; i++) letterPos[i]={0};
    for (int i=0; i<n; i++) letterPos[s[i]-'a'].push_back(i+1);
    int m;
    cin>>m;
    string T;
    
    for (int i=1; i<=m; i++)
    {
        cin>>T;
        for (char c:T) letterCnt[i][c-'a']++;
        int ans=-inf;
        for (int j=0; j<26; j++) ans=max(ans, letterPos[j][letterCnt[i][j]]);
        cout<<ans<<"\n";
    }


}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/