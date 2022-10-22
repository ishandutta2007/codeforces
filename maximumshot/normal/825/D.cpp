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

int const L = 1e6 + 5;

char s[L];
char t[L];
int c1[26];
int c2[26];
int c = 0;

bool check(int x, int fl = 0) {
    int need = 0;
    int ptr = 0;
    for(int add, i = 0;i < 26;i++) {
        add = max(0, c2[i] * x - c1[i]);
        if(add == 0) continue;
        need += add;
        if(need > c) return false;
        if(fl) {
            while(add > 0) {
                if(s[ptr] == '?') {
                    s[ptr] = char(i + 'a');
                    add--;
                }
                ptr++;
            }
        }
    }
    if(fl) while(s[ptr]) { if(s[ptr] == '?') s[ptr] = 'a'; ptr++; }
    return true;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%s %s", s, t);

    for(int i = 0;s[i];i++) {
        if(s[i] != '?') {
            c1[s[i] - 'a']++;
        }else {
            c++;
        }
    }

    for(int i = 0;t[i];i++) {
        c2[t[i] - 'a']++;
    }

    int bl = 0;
    int br = strlen(s) / strlen(t);
    int bm;

    while(br - bl > 1) {
        bm = (bl + br) / 2;
        if(check(bm)) {
            bl = bm;
        }else {
            br = bm - 1;
        }
    }

    if(bl < br && check(br)) {
        check(br, 1);
    }else {
        check(bl, 1);
    }

    printf("%s\n", s);

    return 0;
}