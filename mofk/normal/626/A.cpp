#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

string s; int N;
bool doo(int l, int r) {
    int x = 0, y = 0;
    ff(i, l, r) {
        if (s[i] == 'U') ++x;
        if (s[i] == 'D') --x;
        if (s[i] == 'L') --y;
        if (s[i] == 'R') ++y;
    }
    return (x == 0 && y == 0);
}

int main(void) {
    cin >> N >> s;
    int r = 0;
    ff(i, 0, N - 1) ff(j, i, N - 1) r += doo(i, j);
    cout << r << endl;
    return 0;
}