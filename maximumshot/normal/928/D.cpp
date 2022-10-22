#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

string read_string() {
    string t;
    string s = "";
    while(getline(cin, t)) {
        s += t + "#";
    }
    return s;
}

const int L = 3e5 + 5;

string s;
int len;
int nxt[L][26];
int parent[L];
int cnt[L];
int sz;
int is_end[L];

bool count_string(const string& t) {
    int v = 0;
    for(char c : t) {
        int x = c - 'a';
        if(nxt[v][x] == -1) {
            return false;
        }
        v = nxt[v][x];
    }
    return is_end[v];
}

void add_string(const string& t) {
    int v = 0;
    for(char c : t) {
        int x = c - 'a';
        if(nxt[v][x] == -1) {
            nxt[v][x] = sz++;
            parent[sz - 1] = v;
        }
        v = nxt[v][x];
        cnt[v]++;
    }
    is_end[v] = 1;
}

int query(const string& t) {
    int res = (int)t.size();
    int v = 0;
    for(int i = 0;i < (int)t.size();i++) {
        int x = t[i] - 'a';
        if(nxt[v][x] == -1) break;
        v = nxt[v][x];
        if(cnt[v] == 1) {
            int u = v;
            int d = i + 1;
            int ok = 1;
            int j = i + 1;
            while(j < (int)t.size() && !is_end[u]) {
                x = t[j] - 'a';
                if(nxt[u][x] == -1) {
                    ok = 0;
                    break;
                }
                u = nxt[u][x];
                d++;
                j++;
            }
            if(!is_end[u]) ok = 0;
            if(ok) {
                res = min(res, i + 1 + 1 + (int)t.size() - d);
            }
            break;
        }
    }
    return res;
}

int main() {

    fill(parent, parent + L, -1);
    fill((int*)nxt, (int*)nxt + L * 26, -1);

    sz = 1;

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    s = read_string();
    len = (int)s.size();

    int res = 0;

    for(int i = 0;i < len;i++) {
        if(s[i] < 'a' || s[i] > 'z') {
            res++;
            continue;
        }
        string t = "";
        int j = i;
        while(j < len && s[j] >= 'a' && s[j] <= 'z') {
            t.push_back(s[j]);
            j++;
        }
        j--;

        res += query(t);

        if(!count_string(t)) {
            add_string(t);
        }

        i = j;
    }

    cout << res << "\n";

    return 0;
}