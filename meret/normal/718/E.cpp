#include <bits/stdc++.h>
#include <sys/time.h>

using namespace std;

#define FI first
#define SE second
#define X first
#define Y second
#define ST first
#define ND second
#define MP make_pair
#define PB push_back

typedef long long LL;
typedef vector<int> VI;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))

double getTime() {
	timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec + tv.tv_usec * 1e-6;
}

const int K = 8;
const int N = 100000;

int min_distance[K][K];
VI at_min_distance[K][K];
VI at_max_distance[K][K];
VPII t_freeloaders[K][K][K];

int n;
char s[N + 5];
vector<int> all[K];

const int INF = (int)1e9;

void compute_distances(int x) {
    static int dist[N + 5];
    static bool got[K];
    queue<int> q;
    REP (i, K) {
        got[i] = false;
    }
    got[x] = true;
    REP (i, n) {
        dist[i] = INF;
        if (s[i] == x) {
            dist[i] = 0;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        if (!got[s[c]]) {
            got[s[c]] = true;
            FORE (it, all[s[c]]) {
                if (dist[*it] == INF) {
                    dist[*it] = dist[c] + 1;
                    q.push(*it);
                }
            }
        }
        if (c > 0 && dist[c - 1] == INF) {
            dist[c - 1] = dist[c] + 1;
            q.push(c - 1);
        }
        if (c + 1 < n && dist[c + 1] == INF) {
            dist[c + 1] = dist[c] + 1;
            q.push(c + 1);
        }
    }
    REP (i, K) {
        min_distance[x][i] = INF;
        FORE (it, all[i]) {
            min_distance[x][i] = min(min_distance[x][i], dist[*it]);
        }
        FORE (it, all[i]) {
            if (min_distance[x][i] == dist[*it]) {
                at_min_distance[x][i].PB(*it);
            } else {
                at_max_distance[x][i].PB(*it);
            }
        }
    }
}

void get_freeloaders() {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && j < i + 8; ++j) {
            t_freeloaders[s[i]][s[j]][j - i].PB(MP(i, j));
            t_freeloaders[s[j]][s[i]][j - i].PB(MP(j, i));
        }
    }
}


LL intersection_size(VPII const* freeloaders, const vector<VI const*>& products, const VI& domain) {
    static int t[N + 5];
    FORE (it, domain) {
        t[*it] = 1;
    }
    int needed = 1;
    FORE (it, products) {
        FORE (jt, **it) {
            if (t[*jt] < needed) {
                continue;
            }
            ++t[*jt];
        }
        ++needed;
    }
    LL result = 0;
    if (freeloaders != NULL) {
        FORE (it, *freeloaders) {
            if (t[it->ST] == needed && t[it->ND] == needed) {
                ++result;
            }
        }
    } else {
        int c0 = 0;
        int c1 = 0;
        FORE (it, domain) {
            if (t[*it] == needed) {
                if (s[*it] == s[domain[0]]) {
                    ++c0;
                } else {
                    ++c1;
                }
            }
        }
        result = c0 * (LL) c1;
    }
    FORE (it, domain) {
        t[*it] = 0;
    }
    return result;
}

LL union_size(const VPII& freeloaders, const vector<VI>& products, const VI& domain) {
    int z = products.size() + 1;
    LL result = 0;
    for (int mask = 1; mask < (1 << z); ++mask) {
        VPII const* fp = NULL;
        vector<VI const*> pp;
        if ((mask >> (z - 1)) & 1) {
            fp = &freeloaders;
        }
        REP (i, z - 1) {
            if ((mask >> i) & 1) {
                pp.PB(&products[i]);
            }
        }
        int sign = (__builtin_popcount(mask) & 1) ? 1 : -1;
        result += sign * intersection_size(fp, pp, domain);
    }
    return result;
}

LL get_count_ab(int a, int b, int distance) {
    static bool in_domain[N];
    REP (i, n) {
        in_domain[i] = (s[i] == a || s[i] == b);
    }
    vector<PII> freeloaders;
    vector<VI> products;
    REP (d, distance) {
        FORE (it, t_freeloaders[a][b][d]) {
            freeloaders.PB(*it);
        }
    }
    REP (c, K) {
        int min_cost = min_distance[c][a] + min_distance[c][b] + 1;
        if (min_cost >= distance) {
            continue;
        }
        if (min_cost == distance - 1) {
            VI v = at_min_distance[c][a];
            FORE (it, at_min_distance[c][b]) {
                v.PB(*it);
            }
            products.PB(v);
            continue;
        }
        if (min_cost == distance - 2) {
            FORE (it, at_min_distance[c][a]) {
                in_domain[*it] = false;
            }
            FORE (it, at_min_distance[c][b]) {
                in_domain[*it] = false;
            }
            continue;
        }
        return 0LL;
    }
    VI domain;
    REP (i, n) {
        if (in_domain[i]) {
            domain.PB(i);
        }
    }
    int c0 = 0;
    int c1 = 0;
    FORE (it, domain) {
        if (s[*it] == s[domain[0]]) {
            ++c0;
        } else {
            ++c1;
        }
    }
    if (c0 == 0 || c1 == 0) {
        return 0LL;
    }
    return c0 * (LL)c1 - union_size(freeloaders, products, domain);
}

LL get_count(int distance) {
    if (distance == 1) {
        return (n * (LL) (n - 1)) / 2LL;
    }
    LL result = 0;
    REP (a, K) {
        FOR (b, a + 1, K) {
            result += get_count_ab(a, b, distance);
        }
    }
    return result;
}

int main() {
    cin >> n;
    cin >> s;
    REP (i, n) {
        s[i] -= 'a';
        all[s[i]].PB(i);
    }
    REP (i, K) {
        compute_distances(i);
    }
    get_freeloaders();
    int min_diameter = 0;
    REP (i, K) {
        REP (j, K) {
            if (min_distance[i][j] != INF) {
                min_diameter = max(min_diameter, min_distance[i][j]);
            }
        }
    }
    LL count = 0;
    int diameter = min_diameter;
    for (diameter = min_diameter + 2; ; --diameter) {
        count = get_count(diameter);
        if (count > 0) {
            break;
        }
    }
    cout << diameter << " " << count << endl;
}