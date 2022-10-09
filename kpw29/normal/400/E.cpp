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

int n,m,k,a,b,c,x ,y, zap;
ll N,M,K,A,B,C;
ll WYN = 0;
#define maxn 100100
set <int> s[19];
int bits[maxn][19];
int t[maxn];
ll f(ll x, ll y)
{
    ll dl = y - x + 1;
    if (dl <= 0) return 0;
    return (dl * (dl + 1) )>> 1;
}
void INSERT(int i, int j) //Inserts into ith set ZERO on j - th position
{
    int left = *(--s[i].lower_bound(j));
    int right = *(s[i].upper_bound(j));
    WYN -= (f(left + 1, right - 1) * (1LL << i));
    s[i].insert(j);
    WYN += ((f(left + 1, j - 1) + f(j + 1, right - 1)) * (1LL << i));
}
void DELETE(int i, int j) //Deletes from the ith set the ZERO on j - th position
{
    set <int> ::iterator it = s[i].lower_bound(j);
    it--;
    int left = *it;
    it++; it++;
    int right = *it;
    WYN += (f(left + 1, right - 1) * (1LL << i));
    s[i].erase(j);
    WYN -= ((f(left + 1, j - 1) + f(j + 1, right - 1)) * (1LL << i));
}
int main()
{
    scanf("%d%d", &n, &zap);
    for (int i=0; i<19; ++i) s[i].insert(0), s[i].insert(n + 1);
    for (int i=1; i<=n; ++i) 
    {
        scanf("%d", &t[i]);
        int help = t[i];
        for (int j=0; j<19; ++j)
        {
            bits[i][j] = help & 1;
            help >>= 1;
            if (!bits[i][j]) s[j].insert(i);
        }
    }
    for (int j=0; j<19; ++j)
    {
        int first = 0;
        for (int i=1; i<=n; ++i)
        {
            if (bits[i][j] && first == 0) first = i;
            else if (!bits[i][j]) first = 0;
            if (bits[i][j]) WYN += ((1LL << j) *(i - first + 1));
        }
    }
    while (zap--)
    {
        int poz, ile;
        scanf("%d%d", &poz, &ile);
        int newbit[20];
        int help = ile;
        for (int j=0; j<19; ++j)
        {
            newbit[j] = help & 1;
            help >>= 1;
        }
        for (int j=0; j<19; ++j)
        {
          if (newbit[j] == bits[poz][j]) continue;
          if (newbit[j]) DELETE(j, poz);
          else INSERT(j, poz);
          bits[poz][j] = newbit[j];
        }

        cout << WYN << '\n';
    }
}