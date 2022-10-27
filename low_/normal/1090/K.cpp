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

int masker(string S)
{
    int ret=0;
    for (char c:S) ret|=(1<<(c-'a'));
    return ret;
}

int n;
pair < pair <string, int>, int> P[mn];

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
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>s>>t;
        int u=masker(t);
        while (s.size()>0)
        {
            if ((u&(1<<(s.back()-'a')))==0) break;
            s.pop_back();
        }
        P[i]={{s, u}, i};
    }

    sort(P+1, P+n+1);

    vector <vector <int> > ans;
    ans={{P[1].YY}};
    for (int i=2; i<=n; i++)
    {
        if (P[i].XX!=P[i-1].XX) ans.push_back({P[i].YY});
        else ans.back().push_back(P[i].YY);
    }

    cout<<ans.size()<<"\n";
    for (vector <int> v: ans) 
    {
        cout<<v.size()<<" ";
        for (int i:v) cout<<i<<" ";
        cout<<"\n";
    }


}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/