#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j))

ld PI = acos(-1.0);
int x[1005], y[1005], r[1005], n;
vi padre(1005, -1);
vector<vi> hijo (1005);
bitset<1005> nivel;

inline bool contiene (int a, int b) { //A contiene a B
    return ll(x[a] - x[b]) * ll(x[a] - x[b]) + ll(y[a] - y[b]) * ll(y[a] - y[b]) <= ll(r[a]) * ll(r[a]);
}

void obtArbol () {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ( r[j] > r[i] && contiene(j, i) ){
                if ( padre[i] == -1 || r[padre[i]] > r[j] )
                    padre[i] = j;
            }
        }
        if ( padre[i] != -1 )
            hijo[padre[i]].push_back(i);
    }
}

void obtNivel (int u, bool nvl) {
    nivel[u] = nvl;
    for ( auto v : hijo[u] )
        obtNivel(v, !nvl);
}

double obtRes() {
    ll res = 0;
    for (int i = 0; i < n; i++) 
        if ( padre[i] == -1 || nivel[i] )
            res += ll(r[i]) * ll(r[i]);
        else
            res -= ll(r[i]) * ll(r[i]);

    return ld(res) * PI;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> r[i];

    obtArbol();

    for (int i = 0; i < n; i++)
        if ( padre[i] == -1 )
            obtNivel(i, false);

    printf("%.9lf\n", obtRes());

    return 0;
}