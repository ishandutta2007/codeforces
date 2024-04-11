#include <bits/stdc++.h>

#include <time.h>
#include <random>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const SQRT = 550;
int const N = 300005;
int const alph = 26;

char buffer[N];

// bohr begin

int nxt[N][alph];
int cnt[N];
int sz = 1;
bool endpos[N];

// bohr end

int big_sz = 0;
string s[N];
int nx[N];
bool used[N];
int bor[N][alph];
int id[N];
int bor_sz = 1;

void add_short() {
    int n = strlen(buffer);
    int v = 0;
    for(int i = 0;i < n;i++) {
        if(!nxt[v][buffer[i] - 'a']) {
            nxt[v][buffer[i] - 'a'] = sz++;
        }
        v = nxt[v][buffer[i] - 'a'];
        cnt[v]++;
    }
    endpos[v] = 1;
}

int get_next(int i) {
    if(nx[i] == big_sz) return big_sz;
    else {
        if(!used[nx[i]]) nx[i] = get_next(nx[i]);
        return nx[i];
    }
}

void add_long() {
    s[big_sz] = buffer;
    nx[big_sz] = big_sz + 1;
    used[big_sz] = 1;
    big_sz++;
    int n = strlen(buffer);
    int v = 0;
    for(int i = 0;i < n;i++) {
        if(!bor[v][buffer[i] - 'a']) {
            bor[v][buffer[i] - 'a'] = bor_sz++;
        }
        v = bor[v][buffer[i] - 'a'];
    }
    id[v] = big_sz - 1;
}

void add() {
    if(strlen(buffer) <= SQRT)
        add_short();
    else
        add_long();
}

void del_short() {
    int n = strlen(buffer);
    int v = 0;
    for(int i = 0;i < n;i++) {
        v = nxt[v][buffer[i] - 'a'];
        cnt[v]--;
    }
    endpos[v] = 0;
}

void del_long() {
    int n = strlen(buffer);
    int v = 0;
    for(int i = 0;i < n;i++) {
        v = bor[v][buffer[i] - 'a'];
    }
    used[id[v]] = 0;
}

void del() {
    if(strlen(buffer) <= SQRT)
        del_short();
    else
        del_long();
}

int preff[2 * N];

void calc_preff(string str) {
    int n = (int)str.size();
    preff[0] = 0;
    for(int j, i = 1;i < n;i++) {
        j = preff[i - 1];
        while(j > 0 && str[i] != str[j]) j = preff[j - 1];
        if(str[i] == str[j]) j++;
        preff[i] = j;
    }
}

void calc() {
    int n = strlen(buffer);
    int res = 0;
    for(int i = 0;i < n;i++) {
        for(int v = 0, j = i;j < n && j - i + 1 <= SQRT && nxt[v][buffer[j] - 'a'];j++) {
            v = nxt[v][buffer[j] - 'a'];
            res += endpos[v];
        }
    }
    for(int iter = 0;iter < big_sz;iter = get_next(iter)) {
        if(!used[iter]) continue;
        calc_preff(s[iter] + "#" + buffer);
        for(int i = (int)s[iter].size() + 1;i < (int)s[iter].size() + 1 + n;i++) {
            res += (preff[i] == (int)s[iter].size());
        }
    }
    printf("%d\n", res);
    fflush(stdout);
}

bool solve() {

    int m;
    scanf("%d", &m);

    for(int ty, iter = 0;iter < m;iter++) {
        scanf("%d %s", &ty, buffer);

        if(ty == 1) {
            add();
        }else if(ty == 2) {
            del();
        }else {
            calc();
        }
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}