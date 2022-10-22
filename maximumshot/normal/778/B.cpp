#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 5005;
int const M = 1005;

char buffer[M];

inline void readLine(string & s) {
    scanf("%s", buffer);
    s = buffer;
}

int n, m;
map< string, int > id;
string nw[N];
string a[N];
string op[N];
string b[N];
int ida[N];
int idb[N];
int val[N];

string mx = "";
string mn = "";

int get(int i, int x) {
    int res = 0;
    for(int j = 1;j <= n;j++) {
        if(a[j][0] == '0' || a[j][0] == '1') {
            val[j] = a[j][i] - '0';
        }else {
            int u, v;
            if(a[j][0] == '?') {
                u = x;
            }else {
                u = val[ ida[j] ];
            }
            if(b[j][0] == '?') {
                v = x;
            }else {
                v = val[ idb[j] ];
            }
            if(op[j] == "AND") {
                val[j] = u & v;
            }else if(op[j] == "OR") {
                val[j] = u | v;
            }else {
                val[j] = u ^ v;
            }
        }
        res += val[j];
    }
    return res;
}

void calc() {
    for(int i = 0;i < m;i++) {
        pii t1 = make_pair(+inf, -1);
        pii t2 = make_pair(+inf, -1);
        for(int x = 0;x < 2;x++) {
            int tmp = get(i, x);
            t1 = min(t1, make_pair(-tmp, x));
            t2 = min(t2, make_pair(+tmp, x));
        }
        mx.push_back(t1.second + '0');
        mn.push_back(t2.second + '0');
    }
}

int main() {

    scanf("%d %d", &n, &m);

    for(int i = 1;i <= n;i++) {
        readLine(nw[i]);
        readLine(op[i]);
        readLine(a[i]);
        id[nw[i]] = i;
        if(a[i][0] == '0' || a[i][0] == '1') {
            continue;
        }
        readLine(op[i]);
        readLine(b[i]);
        if(a[i] != "?") ida[i] = id[a[i]];
        if(b[i] != "?") idb[i] = id[b[i]];
    }

    calc();

    for(auto c : mn) printf("%c", c);
    printf("\n");
    for(auto c : mx) printf("%c", c);
    printf("\n");

    return 0;
}