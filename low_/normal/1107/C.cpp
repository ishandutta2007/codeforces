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

int n, k;
int A[mn];
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

    cin>>n>>k;
    for (int i=0; i<n; i++) cin>>A[i];
    cin>>S;
    S.push_back('.');
    A[n]=0;
    priority_queue <int> PQ;
    PQ.push(A[0]);
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        if (S[i]!=S[i-1]) 
        {
            for (int j=0; j<k;j++)
            {
                if (PQ.empty()) break;
                ans+=PQ.top();
                PQ.pop();
            }
            while (!PQ.empty()) PQ.pop();
            PQ.push(A[i]);
        }
        else PQ.push(A[i]);
    }
    cout<<ans;


}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/