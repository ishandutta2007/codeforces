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

void convert(string& s) {
    for(char& c : s) {
        if(c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
        if(c == 'o') {
            c = '0';
        }else if(c == 'l' || c == 'i') {
            c = '1';
        }
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    string s, t;
    int n;

    cin >> s >> n;

    convert(s);

    while(n--) {
        cin >> t;
        convert(t);
        if(s == t) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";

    return 0;
}