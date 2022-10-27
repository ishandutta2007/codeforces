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

int n;
int p[mn];
int x, a, y, b, k;
pii contr[mn];
int newArr[mn];

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ntest;
    cin>>ntest;
    while (ntest--)
    {
        cin>>n;
        for (int i=1; i<=n; i++) 
        {
            cin>>p[i];
            p[i]/=100;
        }
        cin>>x>>a>>y>>b>>k;

        sort(p+1, p+n+1);
        int l=1, r=n+1;
        while (r>l)
        {
            vector <int> V;
            int mid=(l+r)/2;

            for (int i=1; i<=mid; i++) V.push_back((i%a==0)*x+(i%b==0)*y);
            sort(V.begin(), V.end());
            int ret=0;
            for (int i=mid; i>0; i--) ret+=V[i-1]*p[i-mid+n];
            if (ret<k) l=mid+1;
            else r=mid;
        }

        if (l==n+1) cout<<"-1\n";
        else cout<<l<<"\n";


    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/