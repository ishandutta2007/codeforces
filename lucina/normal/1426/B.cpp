#include<bits/stdc++.h>
using namespace std;
int n, m;
using A = array <int, 2>;
using B = array <A, 2>;
B x[500];


bool solve() {
    cin >> n >> m;
//    set <B> setik;

    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 0 ; j < 2 ; ++ j)
        for (int k = 0 ; k < 2 ; ++ k)
            cin >> x[i][j][k];
      //  setik.insert(x[i]);
    }


    if (m % 2) return false;

    for (int i = 1 ; i <= n ; ++ i) {
        if (x[i][0][1] == x[i][1][0]) return true;
 
    }
    return false;

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T --  ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}

/***
[----]
[----]
[----]
[----]

*/