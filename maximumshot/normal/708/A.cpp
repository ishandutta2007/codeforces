#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    string a;

    cin >> a;

    for(int i = 0;i < (int)a.size();i++) {
        if(a[i] == 'a') continue;
        int j = i;
        while(j < (int)a.size() && a[j] > 'a') {
            a[j]--;
            j++;
        }
        cout << a << '\n';
        return true;
    }

    for(int i = 0;i < (int)a.size() - 1;i++) cout << a[i];
    cout << "z\n";

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}