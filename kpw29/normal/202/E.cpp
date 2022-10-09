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
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
#define maxn 1000100
int n,m,k, a, b, x;
long long A, B;

struct pole
{
    int lewo, prawo;
    ll wroc;
    ll niewroc;
};

pole t[maxn];
pole tab[maxn];
int main()
{
    boost;
    cin >> n;
    for (int i=1; i<n; ++i) 
    {
        cin >> t[i].prawo;
        t[i+1].lewo = tab[i + 1].lewo = tab[i].prawo = t[i].prawo;
    }
    pole help;
    help.wroc = help.niewroc = 0;
    t[1] = help; tab[n] = help;
    for (int i=2; i<=n; ++i)
    {
        if (t[i].lewo & 1) 
        {
            t[i].niewroc = max(t[i-1].wroc, t[i-1].niewroc) + t[i].lewo;
            if (t[i].lewo == 1) t[i].wroc = 0;
            else t[i].wroc = (t[i].lewo - 1) + t[i - 1].wroc;
        }
        else
        {
            t[i].niewroc = max(t[i-1].wroc, t[i-1].niewroc) + t[i].lewo - 1;
            t[i].wroc = t[i-1].wroc + t[i].lewo;
        }
    }
    for (int i=n-1; i>0; --i)
    {
        if (tab[i].prawo & 1)
        {
            tab[i].niewroc = max(tab[i+1].wroc, tab[i+1].niewroc) + tab[i].prawo;
            if (tab[i].prawo == 1) tab[i].wroc = 0;
            else tab[i].wroc = (tab[i].prawo - 1) + tab[i + 1].wroc;
        }
        else
        {
            tab[i].niewroc = max(tab[i+1].wroc, tab[i+1].niewroc) + tab[i].prawo - 1;
            tab[i].wroc = tab[i+1].wroc + tab[i].prawo;
        }
    }
    
    ll WYN = 0;
    for (int i=1; i<=n; ++i)
    {
        WYN = max(WYN, tab[i].wroc + t[i].wroc);
        WYN = max(WYN, tab[i].wroc + t[i].niewroc);
        WYN = max(WYN, tab[i].niewroc + t[i].wroc);
    }
    cout << WYN;
}