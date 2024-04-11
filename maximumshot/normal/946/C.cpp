#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;
const double pi = acos(-1.0);

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    string s;

    cin >> s;

    int i = 0;
    for(char c = 'a';c <= 'z';c++) {
        while(i < (int)s.size() && s[i] > c) i++;
        if(i == (int)s.size()) {
            cout << "-1\n";
            return 0;
        }
        s[i] = c;
        i++;
    }

    cout << s << "\n";

    return 0;
}