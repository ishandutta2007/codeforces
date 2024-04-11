#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int , int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int n;
    cin >> n;

    for(int i = 0;i < n;i++) {
        if(i % 2 == 0) {
            cout << "I hate ";
        }else {
            cout << "I love ";
        }
        if(i + 1 == n) cout << "it\n";
        else cout << "that ";
    }



    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}