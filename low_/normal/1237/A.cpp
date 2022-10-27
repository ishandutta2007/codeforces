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

int n, A[mn];
int B[mn], odcnt;

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i=1; i<=n; i++) 
    {
        cin>>A[i];
        B[i]=A[i]%2;
        B[i]=B[i]*B[i];
        odcnt+=B[i];
    }

    for (int i=1; i<=n; i++) A[i]=(A[i]+B[i])/2;
    int temp=0;
    for (int i=1; i<=n; i++) if (B[i]==1)
    {
        A[i]--;
        temp++;
        if (temp>=odcnt/2) break;
    }
    for (int i=1; i<=n; i++) cout<<A[i]<<"\n";
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/