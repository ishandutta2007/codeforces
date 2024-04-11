#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef pair< ll, ll > pll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 100005;

int parent[N];
int color[N];

int find(int x) {
    if(x == parent[x]) return x;
    else {
        int y = find(parent[x]);
        color[x] ^= color[ parent[x] ];
        return parent[x] = y;
    }
}

int get_color(int x) {
    find(x);
    return color[x];
}

int n, m, q;
map< string, int > id;
char buffer[25];

void readLine(string & s) {
    scanf("%s", buffer);
    s = buffer;
}

void init() {
    for(int i = 1;i <= n;i++) {
        parent[i] = i;
        color[i] = 0;
    }
}

int main() {

    srand(time(NULL));

    scanf("%d %d %d", &n, &m, &q);

    {
        set< string > tmp_set;
        string tmp_s;

        for(int i = 1;i <= n;i++) {
            readLine(tmp_s);
            tmp_set.insert(tmp_s);
        }

        n = (int)tmp_set.size();

        int cur = 1;

        for(string s : tmp_set) {
            id[s] = cur++;
        }
    }

//    cout << "ok\n";

    init();

    string su, sv;

    for(int cu, cv, pu, pv, type, u, v, iter = 0;iter < m;iter++) {
        scanf("%d", &type);
        readLine(su);
        readLine(sv);
        u = id[su];
        v = id[sv];

        pu = find(u);
        pv = find(v);
        cu = get_color(u);
        cv = get_color(v);

//        cout << u << " " << v << " : " << pu << " " << pv << "\n";

        if(pu == pv) {
            if(type == 1) {
                if(cu == cv) {
                    puts("YES");
                }else {
                    puts("NO");
                }
            }else {
                if(cu == cv) {
                    puts("NO");
                }else {
                    puts("YES");
                }
            }
        }else {
            if(rand() % 2) {
                swap(pu, pv);
                swap(cu, cv);
                swap(u, v);
            }
            if(type == 1 && color[u] != color[v]) color[pu] ^= 1;
            if(type == 2 && color[u] == color[v]) color[pu] ^= 1;
            parent[pu] = pv;
            puts("YES");
        }
    }

    for(int u, v, iter = 0;iter < q;iter++) {
        readLine(su);
        readLine(sv);
        u = id[su];
        v = id[sv];
        if(find(u) != find(v)) {
            puts("3");
        }else if(get_color(u) != get_color(v)) {
            puts("2");
        }else {
            puts("1");
        }
    }

    return 0;
}