#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef complex<int64> point;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 2000;

int64 cross(point a, point b){
    return imag(conj(a) * b);
}

point stone[7];
point monster[maxn];
point center;

int perm[maxn];

int quad(point a){
    if (real(a) > 0 && imag(a) >= 0) return 0;
    if (real(a) <= 0 && imag(a) > 0) return 1;
    if (real(a) < 0 && imag(a) <= 0) return 2;
    if (real(a) >= 0 && imag(a) < 0) return 3;
    return -1;
}

bool compare(int a, int b){
    point pa = monster[a] - center, pb = monster[b] - center;
    int qa = quad(pa), qb = quad(pb);
    if (qa != qb) return qa < qb;
    int64 ar = cross(pa, pb);
    if (ar == 0) return norm(pa) < norm(pb);
    return ar > 0;
}

int ind[7][maxn];
bool afraid[maxn];
bool dead[maxn];

int killed[7], pnt = 0;
int order[7], top;

vector<vi> L[7];

point read(){
    int64 x, y; cin >> x >> y;
    return point(x, y);
}

int k, n;

bool myfind(vector<int> &v, int p){
    for (auto aa : v) if (aa == p) return true;
    return false;
}

bool kill(int monster_id){
    if (top == 0) return false;
    int stone = order[ --top ], t = 0;
    int dir = ind[ stone ][ monster_id ];

    // assert(myfind(L[stone][dir], monster_id));

    while ( L[stone][dir][t] != monster_id )
        if (!dead[ L[stone][dir][t] ] && !kill( L[stone][dir][t] ))
            return false;
        else t++;

    killed[ pnt++ ] = monster_id;
    dead[ monster_id ] = true;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;

    for (int i = 0; i < k; ++i) stone[i] = read();
    for (int i = 0; i < n; ++i) monster[i] = read(), perm[i] = i;

    for (int i = 0; i < k; ++i){
        center = stone[i];

        sort(perm, perm + n, compare);

        for (int j = 0, k; j < n; j = k){
            vi I; int idx = L[i].size();
            point p = monster[ perm[j] ] - center;
            int q = quad(p);

            for (k = j; k < n; ++k){
                point pp = monster[ perm[k] ] - center;
                int qq = quad(pp);
                if (qq != q || cross(p, pp) != 0) break;

                ind[i][ perm[k] ] = idx;
                I.push_back(perm[k]);
            }

            L[i].push_back(I);
        }
    }

    int answer = 0;

    for (int i = 0, afraid; i < n; ++i){
        afraid = 0;

        for (int j = 0; j < k; ++j) order[j] = j;

        do{
            top = k;
            afraid = kill(i);

            for (int j = 0; j < pnt; ++j) dead[ killed[j] ] = false;
            pnt = 0;

        } while (!afraid && next_permutation(order, order + k));

        answer += afraid;
    }

    cout << answer << endl;

    return 0;
}