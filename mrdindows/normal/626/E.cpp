//All the C++ libraries.
//#include <bits/stdc++.h>

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef long long ll;

#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define prii(a, b)	printf("%d %d\n",a, b)

#define loop(n)          for(int i = 0; i < (n); i++)
#define lp(x, s, e)      for(int x = (s); x < (e); x++)
#define lpe(x, s, e)     for(int x = (s); x <= (e); x++)
#define iterate(v, i)    for(int i = 0; i < (v).size(); i++)

#define SetBit(x, bit)      ((x) |= 1 << (bit))
#define ClrBit(x, bit)      ((x) &= ~(1 << (bit)))
#define ToggleBit(x, bit)   ((x) ^= 1 << (bit))
#define ReadBit(x, bit)     (((x) & 1 << (bit)) != 0)

#define MP make_pair
#define PB push_back
#define all(a)   a.begin(),a.end()
#define clr(x, val)	memset((x), (val), sizeof(x))	//Not tested.
#define endl '\n'

#define MAXN    200000+9
int n;
int a[MAXN];
ll com[MAXN];


double ValAt(int i, int k)
{
    ll sum = a[i] + com[n]-com[n-k] + com[i-1]-com[i-1-k];
    return sum/(double)(2*k+1);
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    cin >> n;
    lpe(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1);

    if(n <= 2)
    {
        cout << n << endl;
        lpe(i, 1, n) cout << a[i] << " ";
        cout << endl;
        return 0;
    }

    com[0] = 0;
    lpe(i, 1, n)    com[i] = com[i-1]+a[i];

    double bestVal = 0;
    int besti = 1, bestSize = 1;

    for(int i = 2; i < n; i ++)
    {
        double bestAv = 0;
        int size;
        int s = 1, e = min(i-1, n-i);

        while(s <= e)
        {
            int k = (s+e)/2;

            ll sum1 = a[i] + com[n]-com[n-k] + com[i-1]-com[i-1-k];
            ll sum2 = a[i] + com[n]-com[n-(k-1)] + com[i-1]-com[i-1-(k-1)];
            double av1 = sum1/(double)(2*k+1);
            double av2 = sum2/(double)(2*(k-1)+1);
            //double av1 = ValAt(i, k);
            //double av2 = ValAt(i, k-1);

            if(av1>av2)
            {
                s = k+1;
                bestAv = av1;
                size = 2*k+1;
            }
            else e = k-1;
        }

        double val = bestAv-a[i];   ///mean - median
        if(val > bestVal)
        {
            bestVal = val;
            besti = i;
            bestSize = size;
        }
    }

    // blasdadwqee12312123123
    vi v;
    v.PB(a[besti]);
    int k = (bestSize-1)/2;

    for(int i = besti-1; i >= besti-k; i--)
        v.PB(a[i]);

    for(int i = n; i > n-k; i--)
        v.PB(a[i]);

    sort(all(v));
   
    cout << bestSize << endl;
    for(auto x: v) cout << x << " ";
    cout << endl;
    return 0;
}