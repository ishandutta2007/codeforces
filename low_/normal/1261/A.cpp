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

int n, k;
string S;

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
        cin>>n>>k;
        cin>>S;
        vector <pii> ans={};
        string SA="";
        for (int i=1; i<k; i++) SA+="()";
        int temp=(n-(k-1)*2)/2;
        for (int i=0; i<temp; i++) SA+='(';
        for (int i=0; i<temp; i++) SA+=')';
        
        for (int i=0; i<S.size(); i++)
        {
            if (S[i]==SA[i]) continue;
            int p=i+1;
            while (p<n)
            {
                if (S[i]!=S[p]) break;
                p++;
            }

            // cerr<<"... "<<i<<" "<<p<<"\n";;

            ans.push_back({i+1, p+1});
            reverse(S.begin()+i, S.begin()+p+1);
        }

        // cerr<<S<<"\n"<<SA<<"\n";
        cout<<ans.size()<<"\n";
        for (pii p: ans) cout<<p.XX<<" "<<p.YY<<"\n";

    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/