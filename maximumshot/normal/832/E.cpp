#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod = 5;

int const rev[5] = {0, 1, 3, 2, 4};

inline int Sum(int a, int b) {
    return (a + b) % mod;
}

inline int Mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int Del(int a, int b) {
    return Mul(a, rev[b]);
}

inline int Magic(int x) {
    return (x % mod + mod) % mod;
}

inline void Add(int & x, int y) {
    x = Sum(x, y);
}

int const N = 505;

char buffer[N];

inline void readLine(string & s) {
    scanf("%s", buffer);
    s = buffer;
}

int n, m;
string s[N];

int mt[N][N];
vector< pair< pii, int > > cf;
int ra;
int row;
int pw[N];

void build() {

    pw[0] = 1;
    for(int i = 1;i < N;i++) {
        pw[i] = (1ll * pw[i - 1] * 5) % (inf + 7);
    }

    for(int i = 0;i < m;i++) {
        for(int j = 0;j < n;j++) {
            mt[i][j] = s[j][i] - 'a';
        }
    }

#ifdef debug
    cout << "#debug\n";
    cout << "\nafter init\n";

    for(int i = 0;i < m;i++) {
        for(int j = 0;j < n;j++) {
            cout << mt[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n\n";
#endif

    for(int col = 0;col < n;col++) {
        int best = -1;
        for(int i = row;i < m;i++) {
            if(mt[i][col] > 0) {
                best = i;
                break;
            }
        }
        if(best == -1) {
            continue;
        }
        if(best != row) {
            for(int j = 0;j < n;j++) {
                swap(mt[row][j], mt[best][j]);
            }
            cf.push_back(make_pair(make_pair(row, best), -1));
        }
        for(int i = row + 1;i < m;i++) {
            int coef = Magic(-Del(mt[i][col], mt[row][col]));
            for(int j = 0;j < n;j++) {
                Add(mt[i][j], Mul(coef, mt[row][j]));
            }
            cf.push_back(make_pair(make_pair(row, i), coef));
        }
        ra++;
        row++;
    }

#ifdef debug
    cout << "#debug\n";
    for(int i = 0;i < m;i++) {
        for(int j = 0;j < n;j++) {
            cout << mt[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "row = " << row << "\n";
    cout << "rank(A) = " << ra << "\n";
#endif
}

int query() {
    string ask;
    readLine(ask);

    for(int i = 0;i < m;i++) {
        mt[i][n] = ask[i] - 'a';
    }

    for(pair< pii, int > iter : cf) {
        int from, to, value;
        tie(from, to) = iter.first;
        value = iter.second;
        if(value == -1) {
            swap(mt[to][n], mt[from][n]);
        }else {
            Add(mt[to][n], Mul(mt[from][n], value));
        }
    }

    for(int i = row;i < m;i++) {
        if(mt[i][n] > 0) {
            return 0;
        }
    }

    return pw[n - ra];
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int i = 0;i < n;i++) {
        readLine(s[i]);
    }

    build();

    int q;

    scanf("%d", &q);

    for(int iter = 0;iter < q;iter++) {
        printf("%d\n", query());
    }

    return 0;
}