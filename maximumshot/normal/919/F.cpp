#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned int ui;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

unordered_map< string, int > type;
unordered_set< string > used;
unordered_map< string, int > deg;
unordered_map< string, vec< string > > gr;

inline void swap_player(string& s) {
    for(int i = 0;i < 5;i++) {
        swap(s[i], s[i + 5]);
    }
}

void dfs(string state) {
    used.insert(state);
    auto& tmp = gr[state];
    for(string from : tmp) {
        if(used.count(from)) continue;
        if(type[state] == (1 << 0)) {
            type[from] = 1 << 1;
        }else if(--deg[from] == 0) {
            type[from] = 1 << 0;
        }else {
            continue;
        }
        dfs(from);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    vec< string > arr;

    for(int c0 = 0;c0 <= 8;c0++) {
        for(int c1 = 0;c0 + c1 <= 8;c1++) {
            for(int c2 = 0;c0 + c1 + c2 <= 8;c2++) {
                for(int c3 = 0;c0 + c1 + c2 + c3 <= 8;c3++) {
                    int c4 = 8 - c0 - c1 - c2 - c3;
                    string s(5, '0');
                    s[0] += c0;
                    s[1] += c1;
                    s[2] += c2;
                    s[3] += c3;
                    s[4] += c4;
                    arr.push_back(s);
                }
            }
        }
    }

    for(string s1 : arr) {
        for(string s2 : arr) {
            if(s1[0] == '8' || s2[0] == '8') continue;
            for(int a = 0;a < 5;a++) {
                if(s1[a] == '0') continue;
                for(int b = 0;b < 5;b++) {
                    if(s2[b] == '0') continue;
                    if((a * b) == 0) continue;
                    int c = (a + b) % 5;
                    string t = s1;
                    t[a]--;
                    t[c]++;
                    deg[s1 + s2]++;
                    gr[s2 + t].push_back(s1 + s2);
                }
            }
        }
    }

    for(string s : arr) {
        if(s[0] == '8') continue;
        string t = s + "80000";
        type[t] = 1 << 0;
        dfs(t);
    }

    int T;

    scanf("%d", &T);

    while(T--) {
        int f;
        scanf("%d", &f);
        string s1(5, '0');
        string s2(5, '0');
        for(int x, i = 0;i < 8;i++) {
            scanf("%d", &x);
            s1[x]++;
        }
        for(int x, i = 0;i < 8;i++) {
            scanf("%d", &x);
            s2[x]++;
        }
        if(!f) {
            int ty = type[s1 + s2];
            if(!ty) {
                puts("Deal");
            }else if(ty == (1 << 0)) {
                puts("Bob");
            }else {
                puts("Alice");
            }
        }else {
            int ty = type[s2 + s1];
            if(!ty) {
                puts("Deal");
            }else if(ty == (1 << 0)) {
                puts("Alice");
            }else {
                puts("Bob");
            }
        }
    }

    return 0;
}