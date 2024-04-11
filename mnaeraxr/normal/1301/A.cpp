#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <assert.h>

#define endl '\n'

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    for (int i = 0; i < t; ++i) {
        string a, b, c; cin >> a >> b >> c;
        bool ok = true;

        for (int i = 0; i < (int)a.length() && ok; ++i) {
            if (a[i] == c[i] || b[i] == c[i]){

            } else ok = false;
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}