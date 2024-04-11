#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int o = count(s.begin(), s.end(), 'n');
    int z = count(s.begin(), s.end(), 'z');

    for (int i = 0; i < o; i++) cout << "1 ";
    for (int i = 0; i < z; i++) cout << "0 ";
    
    return 0;
}