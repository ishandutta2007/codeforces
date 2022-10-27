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

    string s, t;
    int T;
    cin>>T;
    while (T--)
    {
        cin>>s>>t;
        sort(s.begin(), s.end());
        bool b=0;
        // cerr<<T<<"\n";
        // cerr<<t.size()<<" "<<s.size()<<' '<<t.size()-s.size()<<"\n";
        if (s.size()<=t.size()) for (int i=0; i<=t.size()-s.size(); i++)
        {
            // cerr<<i<<" ";
            string temp=t;
            sort(temp.begin()+i, temp.begin()+i+s.size());

            if (s==temp.substr(i, s.size())) b=1;
        }
        // cerr<<"\n";
        if (b) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: ttuandung1803@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie.exe/