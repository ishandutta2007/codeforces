#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N; string s;
int a, b, c;

bool check(void) {
    if (b && c) return 1;
    if (b == 0 && c == 0) return 1;
    if (a == 0) return 0;
    if (b == 1 || c == 1) return 0;
    return 1;
}

int main(void) {
    cin >> N >> s;
    ff(i, 0, N - 1) if (s[i] == 'B') ++a; else if (s[i] == 'G') ++b; else ++c;
    if (check()) cout << 'B';
    swap(a, b);
    if (check()) cout << 'G';
    swap(a, c);
    if (check()) cout << 'R';
    return 0;
}