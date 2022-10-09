#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
#define OUT(x) { cout << x; return 0; }
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a,b,c,k;
int t[4][3];
int wyk[4];
int main()
{
    cin >> n;
    int sum = 0;
    for (int i=0; i<3; ++i) {cin >> t[i][0] >> t[i][1]; sum += t[i][0];}
    int delay = n - sum;
    for (int i=0; i<3; ++i)
        for (int j=t[i][0]+1; j<=t[i][1]; ++j)
        {
            if (delay)
            {
                delay--;
                wyk[i]++;
            }
        }
    cout << wyk[0] + t[0][0] << ' ' << wyk[1]+ t[1][0] << ' ' << wyk[2] + t[2][0];
    
    return 0;
}