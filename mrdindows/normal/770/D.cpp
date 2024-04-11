#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <cassert>
#include <memory.h>
#include <deque>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define DBN1(a)           cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)         cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)       cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)     cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN6(a,b,c,d,e,f) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<", "<<#f<<"="<<(f)<<"\n"

const double EPS = 1e-9;
const int INF = 1011111111;
const int MD = 1000000000 + 7;
const double PI = acos(-1.0);
const int MAX_N = 1 << 10;

int n;

char b[MAX_N][MAX_N];
auto a = b + MAX_N / 2;

void solve() {
    memset(b, ' ', sizeof(b));
    vector<int> h(n);
    string s;
    cin >> s;
    int balance = 0;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '[') {
            h[i] = balance;
            balance--;
        }
        else {
            balance++;
            h[i] = balance;
        }
    }
    int mn = *min_element(h.begin(), h.end());
    for (int& value : h) {
        value -= mn;
    }
    int r = -1;
    for (int j = 0; j < n; j++) {
        r++;
        if (s[j] == ']' && s[j - 1] == '[') {
            r += 3;
        }
        a[-h[j] - 1][r] = a[h[j] + 1][r] = '+';
        int l = (s[j] == '[') ? (r + 1) : (r - 1);
        a[-h[j] - 1][l] = a[h[j] + 1][l] = '-';
        for (int i = -h[j]; i <= h[j]; i++) {
            a[i][r] = '|';
        }
    }
    for (int i = mn - 1; i <= -mn + 1; i++) {
        for (int j = 0; j <= r; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}


int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    bool needDelim = false;
    while (cin >> n) {
        if (needDelim) {
            cerr << "_______________\n";
        }
        solve();
        needDelim = true;
    }
    
    return 0;
}	

/*
 
 */