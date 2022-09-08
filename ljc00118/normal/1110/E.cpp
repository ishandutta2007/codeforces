#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2e5 + 5;

map <int, int> wxw1, wxw2;
map <int, int> :: iterator it;
int a[N], b[N];
int s1[N], s2[N];
int n, ans;

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i]);
    for(register int i = 1; i <= n; i++) read(b[i]);
    if(a[1] != b[1] || a[n] != b[n]) {
        cout << "No" << endl;
        return 0;
    }
    for(register int i = 1; i < n; i++) {
        s1[i] = a[i + 1] - a[i];
        s2[i] = b[i + 1] - b[i];
        wxw1[abs(s1[i])]++;
        wxw2[abs(s2[i])]++;
    }
    for(it = wxw1.begin(); it != wxw1.end(); ++it) {
        if(wxw1[it -> first] != wxw2[it -> first]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}