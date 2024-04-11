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

string S;
int A[mn];
int n;

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
        cin>>S;
        n=S.size();
        vector<int> ans;
        for (int i=0; i<n; i++) A[i]=0;

        for (int i=0; i<n-4; i++) 
        {
            if (S.substr(i, 5)=="twone") A[i+2]=1, ans.push_back(i+3);
        }

        for (int i=0; i<n-2; i++) if (A[i]==0 && A[i+1]==0 && A[i+2]==0)
        {
            string str=S.substr(i, 3);
            if (str=="one"||str=="two") A[i+1]=1, ans.push_back(i+2);
        }

        cout<<ans.size()<<'\n';
        for (int i:ans) cout<<i<<" ";
        cout<<"\n";
    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/