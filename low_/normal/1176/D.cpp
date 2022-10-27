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
#define pm 3000005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int IP[pm];
vector <int> primes={-1};
int cnt[pm];

void eratos()
{
    for (int i=0; i<pm; i++) IP[i]=i;
    for (int i=2; i<pm; i++) if (IP[i]==i)
    {
        for (int j=i*i; j<pm; j+=i) if (IP[j]==j) IP[j]=i;
        primes.push_back(i);
    }
}

bool isPrime(int u)
{
    return (IP[u]==u);
}

int n;
vector <int> A, extA, B;

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    eratos();
    cin>>n;
    B.assign(n*2, 0);
    for (int i=0; i<2*n; i++) 
    {
        cin>>B[i];
        cnt[B[i]]++;
    }

    sort(B.begin(), B.end());

    for (int i=2*n-1; i>-1; i--) if (!isPrime(B[i]) && cnt[B[i]]>0)
    {
        int x=B[i], y=B[i]/IP[B[i]];
        cnt[x]--;
        cnt[y]--;
        A.push_back(x);
        extA.push_back(y);
    }

    for (int i=0; i<2*n; i++) if (isPrime(B[i]) && cnt[B[i]]>0)
    {
        int x=B[i], y=primes[B[i]];
        cnt[x]--;
        cnt[y]--;
        A.push_back(x);
        extA.push_back(y);
    }

    for (int i:A) cout<<i<<" ";



}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/