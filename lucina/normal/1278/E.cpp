#pragma GCC optimize("Ofast")
#pragma GCC target("sse4.1,sse4.2,ssse3,sse3,sse2,sse,avx")
#pragma GCC target("avx2")
 
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
 
char getChar() {
    static char buf[1 << 16];
    static int pos = 0;
    static int size = 0;
    if (pos == size) {
        size = (int)fread(buf, 1, 1 << 16, stdin);
        pos = 0;
    }
    if (pos == size) {
        return -1;
    }
    return buf[pos++];
}
 
void getStr(char* s) {
    char c = ' ';
    while (std::isspace(c)) {
        c = getChar();
    }
    while (!std::isspace(c)) {
        *s = c;
        s++;
        c = getChar();
    }
    *s = '\0';
}
 
int getInt() {
    char c = '?';
    while (!(c == '-' || ('0' <= c && c <= '9'))) { c = getChar(); }
    bool neg = false;
    if (c == '-') {
        neg = true;
        c = getChar();
    }
    int ret = 0;
    while ('0' <= c && c <= '9') {
        ret *= 10;
        ret += (c - '0');
        c = getChar();
    }
    return neg ? -ret : ret;
}
 
void putChar(char c) {
    static char buf[1 << 16];
    static int size = 0;
    if (size == (1 << 16) || c == -1) {
        fwrite(buf, 1, size, stdout);
        size = 0;
    }
    if (c != -1) {
        buf[size++] = c;
    }
}
 
void putStr(const char* s) {
    for (const char *it = s; *it != '\0'; it++) {
        putChar(*it);
    }
}
 
void putInt(int v) {
    static char stack[16];
    int size = 0;
    if (v < 0) {
        putChar('-');
        v = -v;
    }
    do {
        stack[size++] = char((v % 10) + '0');
        v /= 10;
    } while (v > 0);
    while (size > 0) {
        putChar(stack[--size]);
    }
}
 
int const nax = 5e5 + 10;
 
int n, sz[nax];
std::vector<int> a[nax];
int ans[nax][2];
 
void dfs_sz (int nod = 1, int from = 0) {
    sz[nod] = 1;
    for (int i : a[nod])
        if (i != from) dfs_sz(i, nod), sz[nod] += sz[i];
 
}
 
void solve (int nod, int from, int l) {
    int start = ans[nod][1] = l + (from == 0 ? (int)a[nod].size() + 1: (int)a[nod].size() - 1);
    int real_start = start + 1;
    for (int to : a[nod]) {
        if (to != from) {
            ans[to][0] = -- start;
            solve(to, nod, real_start);
            real_start += 2 * sz[to] - 1;
        }
    }
}
 
int main () {
 
    scanf("%d", &n);
    for (int i = 1 ; i < n ; ++ i) {
        int u = getInt(), v = getInt();
        a[u].push_back(v);
        a[v].push_back(u);
    }
 
    dfs_sz();
    ans[1][0] = 1;
    solve(1, 0, 1);
 
 
    for (int i = 1 ; i <= n ; ++ i) {
        putInt(ans[i][0]) ; putChar(' ');
        putInt(ans[i][1]) ; putChar('\n');
    }
    putChar(-1);
}