#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define pb push_back
#define boost ios_base::sync_with_stdio(false)
#define milion 1000100
#define tysiac 1010
#define dwa_tysiace 2010
#define sto_tysiecy 100100
typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned int ui;
typedef pair <int, int> BONG;
typedef pair <BONG, BONG> LONG;
const int inf = 1e9+9;
const int mod = 1e9+7;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a,b;

int t[27][27];
char s[milion];
int slowo[15];
int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; ++i)
    {
        scanf("%s", s+1);
        int dl = 1;
        while( s[dl]) ++dl;
        --dl;
        for (int i=1; i<=dl; ++i) slowo[i] = s[i] - 'a';
    
        for (int i=0; i<26; ++i)
        {
            if (t[i][slowo[1]] != 0) t[i][slowo[dl]] = max(t[i][slowo[dl]], t[i][slowo[1]] + dl);
        }
        t[slowo[1]][slowo[dl]] = max(t[slowo[1]][slowo[dl]], dl);
    }
    int wyn =0;
    
    for (int i=0; i<26; ++i) wyn = max(wyn, t[i][i]);
    printf("%d", wyn);
}