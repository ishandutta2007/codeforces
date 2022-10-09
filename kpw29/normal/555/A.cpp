#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> BONG;
typedef pair <ll, ll> LONG;
typedef pair <ld, ld> DONG;
typedef pair <BONG, BONG> PAIR;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a,b,c,p,q, k;
ll N,M,P,Q,A,B,C;
int x, t[milion];
int main()
{
    scanf("%d%d", &n, &k);
    int wyn = 1; int chains = 0, allchains = 0;
    int ILE = 0;
    for (int i=1; i<=k; ++i) 
    {
        --wyn;
        scanf("%d", &x); bool zle = false;
        for (int j=1; j<=x; ++j) 
        {
            scanf("%d", &t[j]);
            if (t[j] != j) zle = true;
            if (zle) wyn += 2;
        }
        allchains += chains;

    }
    //cout << ILE << ' ' << wyn << endl;
    printf("%d ", wyn);
    
    return 0;
}