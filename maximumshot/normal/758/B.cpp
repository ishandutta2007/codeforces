#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    string s;
    cin >> s;

    map< char, int > id;

    for(int i = 0;i < (int)s.size();i++) {
        if(s[i] == '!') continue;
        id[s[i]] = i % 4;
    }


    vec< int > cnt(4);

    for(int i = 0;i < (int)s.size();i++) {
        if(s[i] == '!') {
            cnt[i % 4]++;
        }
    }


    cout << cnt[ id['R'] ] << " " << cnt[ id['B'] ] << " " << cnt[ id['Y'] ] << " " << cnt[ id['G'] ] << "\n";

    return 0;
}