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
#define mn 300005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int n, q;
int A[mn];
vector <pair <int, pii> > V; // value - left ind, right ind
int L[mn], R[mn];

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    while (q--)
    {
        V.clear();
        cin>>n;
        for (int i=1; i<=n; i++) 
        {
            cin>>A[i];
            L[i]=inf;
            R[i]=-inf;
        }
        for (int i=1; i<=n; i++)
        {
            L[A[i]]=min(i, L[A[i]]);
            R[A[i]]=max(i, R[A[i]]);
        }

        for (int i=1; i<=n; i++) if (L[i]<=n)
        {
            V.push_back({i, {L[i], R[i]}});
        }

        sort(V.begin(), V.end());
        int l=0, r=0;
        int ans=1;
        while (1)
        {
            if (r==V.size()-1) break;
            if (l>r) r++;
            else if (V[r+1].YY.XX>V[r].YY.YY) r++;
            else l++;
            ans=max(ans, r-l+1);
        }
        cout<<V.size()-ans<<"\n";

    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/