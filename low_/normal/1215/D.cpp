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

    int n;
    string S;
    cin>>n>>S;
    n/=2;
    string s1=S.substr(0, n), s2=S.substr(n, n);
    int sig1=0, sig2=0;
    int q1=0, q2=0;
    for (int i=0; i<n; i++) 
    {
        if (s1[i]!='?') sig1+=s1[i]-'0';
        else q1++;
        if (s2[i]!='?') sig2+=s2[i]-'0';
        else q2++;
    }

    if (sig2-sig1==(q1-q2)/2*9) cout<<"Bicarp";
    else cout<<"Monocarp";
    
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/