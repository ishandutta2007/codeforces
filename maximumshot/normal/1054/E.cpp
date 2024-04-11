#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int MAX_LEN = 1e5 + 5;
char buffer[MAX_LEN];

inline void read_deque(deque< int > &d) {
    scanf("%s", buffer);
    int sz = strlen(buffer);
    d.resize(sz);
    for(int i = 0;i < sz;i++) {
        d[i] = buffer[i] - '0';
    }
}

vec< pair< pii, pii > > queries;

inline void add_turn(int x1, int y1, int x2, int y2) {
    queries.push_back({ {x1 + 1, y1 + 1}, {x2 + 1, y2 + 1} });
}

const int N = 305;
deque< int > st[N][N], fn[N][N], d[N][N];
int n, m;

inline void do_turn(int x1, int y1, int x2, int y2) {
    assert(!(x1 == x2 && y1 == y2));
    assert(x1 == x2 || y1 == y2);
    assert(!d[x1][y1].empty());
    add_turn(x1, y1, x2, y2);
    d[x2][y2].push_front(d[x1][y1].back());
    d[x1][y1].pop_back();
}

inline void do_move(int x1, int y1, int x2, int y2, int bx = -1, int by = -1) {
    assert(!(x1 == x2 && y1 == y2));
    if(x1 == x2 || y1 == y2) {
        do_turn(x1, y1, x2, y2);
    }else {
        do_turn(x1, y1, bx, by);
        do_turn(bx, by, x2, y2);
    }
}

void print() {
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cout << "\"";
            for(int x : d[i][j]) {
                cout << x;
            }
            cout << "\"";
            cout << " ";
        }
        cout << "\n";
    }
}

deque< int > concat(const deque< int > &d1, const deque< int > &d2) {
    deque< int > res;
    for(int x : d1) res.push_back(x);
    for(int x : d2) res.push_back(x);
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif


    scanf("%d %d", &n, &m);

    int tot = 0;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            read_deque(st[i][j]);
            tot += (int)st[i][j].size();
        }
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            read_deque(fn[i][j]);
        }
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            d[i][j] = st[i][j];
        }
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            int c[2];
            c[0] = count(ALL(d[i][j]), 0);
            c[1] = count(ALL(d[i][j]), 1);
            while((c[0] > 0 && j > 0) || (c[1] > 0 && j + 1 < m)) {
                int x = d[i][j].back();
                c[x]--;
                if(x) {
                    if(j + 1 < m) {
                        do_turn(i, j, i, m - 1);
                    }else {
                        if(i > 0) {
                            do_turn(i, m - 1, 0, m - 1);
                        }else {
                            do_turn(i, m - 1, n - 1, m - 1);
                        }
                    }
                }else {
                    if(j > 0) {
                        do_turn(i, j, i, 0);
                    }else {
                        if(i > 0) {
                            do_turn(i, 0, 0, 0);
                        }else {
                            do_turn(0, 0, n - 1, 0);
                        }
                    }
                }
            }
        }
    }

    for(int i = 0;i < n;i++) {
        for(int j = 1;j + 1 < m;j++) {
            int I = 0, J = 0;
            for(int it = (int)fn[i][j].size() - 1;it >= 0;it--) {
                int x = fn[i][j][it];
                if(x) {
                    while(d[I][m - 1].empty()) I++;
                    do_move(I, m - 1, i, j, i, m - 1);
                }else {
                    while(d[J][0].empty()) J++;
                    do_move(J, 0, i, j, i, 0);
                }
            }
        }
    }

    for(int i = 0;i < n;i++) {
        if(i != n - 2) {
            while(!d[i][0].empty()) {
                do_turn(i, 0, n - 2, 0);
            }
        }
        if(i != n - 1) {
            while(!d[i][m - 1].empty()) {
                do_turn(i, m - 1, n - 1, m - 1);
            }
        }
    }

    for(int i = 0;i + 2 < n;i++) {
        int l1 = (int)fn[i][0].size();
        int l2 = (int)fn[i][m - 1].size();
        for(int it = l1 - 1;it >= 0;it--) {
            int x = fn[i][0][it];
            if(!x) {
                do_turn(n - 2, 0, i, 0);
            } else {
                do_turn(n - 1, m - 1, n - 1, 0);
                do_turn(n - 1, 0, i, 0);
            }
        }
        for(int it = l2 - 1;it >= 0;it--) {
            int x = fn[i][m - 1][it];
            if(x) do_turn(n - 1, m - 1, i, m - 1);
            else {
                do_turn(n - 2, 0, n - 2, m - 1);
                do_turn(n - 2, m - 1, i, m - 1);
            }
        }
    }

    deque< int > q1 = concat(fn[n - 1][0], fn[n - 2][0]);
    deque< int > q2 = concat(fn[n - 2][m - 1], fn[n - 1][m - 1]);

    reverse(ALL(q1));
    reverse(ALL(q2));

    for(int x : q1) {
        if(x) {
            do_turn(n - 1, m - 1, n - 1, 0);
        }else {
            do_turn(n - 2, 0, n - 1, 0);
        }
    }

    for(int x : q2) {
        if(x) {
            do_turn(n - 1, m - 1, n - 2, m - 1);
        }else {
            do_turn(n - 2, 0, n - 2, m - 1);
        }
    }

    int l1 = (int)fn[n - 2][0].size();
    int l2 = (int)fn[n - 1][m - 1].size();

    while(l1--) do_turn(n - 1, 0, n - 2, 0);
    while(l2--) do_turn(n - 2, m - 1, n - 1, m - 1);

//    print();

//    assert(4 * tot >= (int)queries.size());

    printf("%d\n", (int)queries.size());

    for(pair< pii, pii > prpr:  queries) {
        pii p1, p2;
        tie(p1, p2) = prpr;
        printf("%d %d %d %d\n", p1.first, p1.second, p2.first, p2.second);
    }

    return 0;
}