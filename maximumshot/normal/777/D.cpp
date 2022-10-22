#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 500005;

char buffer[N];

inline void readLine(string & s) {
    scanf("%s", buffer);
    s = buffer;
}

int n;
string a[N];
int last[N];
int sz;
int nxt[N][26];
int cnt[N][26];
int who[N];

void init() {
    for(int i = 0;i < N;i++) {
        who[i] = -1;
        for(int j = 0;j < 26;j++) {
            nxt[i][j] = -1;
        }
    }
    sz = 1;
}

int main() {

//    freopen("input.txt", "r", stdin);

    init();

    scanf("%d", &n);

    for(int i = 0;i < n;i++) {
        readLine(a[i]);
        int v = 0;
        for(int x, j = 1;j < (int)a[i].size();j++) {
            x = a[i][j] - 'a';
            if(nxt[v][x] == -1) {
                nxt[v][x] = sz++;
            }
            cnt[v][x]++;
            v = nxt[v][x];
        }
        last[v]++;
    }

    for(int i = 0;i < n;i++) {
        int v = 0;
        int j_last = (int)a[i].size();
        for(int x, j = 1;j < (int)a[i].size();j++) {
            x = a[i][j] - 'a';
            int ok = last[v] > 0;
            for(int y = 0;y < x;y++) {
                if(cnt[v][y] > 0) {
                    ok = 1;
                    break;
                }
            }
            if(ok) {
                if(j < j_last) {
                    j_last = j;
                    who[v] = max(who[v], i);
                }
            }
            cnt[v][x]--;
            v = nxt[v][x];
        }
        last[v]--;
        if(j_last == (int)a[i].size()) {
            who[v] = max(who[v], i);
        }
    }

    for(int i = 0;i < n;i++) {
        int v = 0;
        printf("#");
        for(int x, j = 1;j < (int)a[i].size();j++) {
            if(i <= who[v]) break;
            x = a[i][j] - 'a';
            printf("%c", a[i][j]);
            v = nxt[v][x];
        }
        printf("\n");
    }

    return 0;
}