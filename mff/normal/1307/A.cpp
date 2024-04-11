#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <random>
#include <string>

#define endl '\n'

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--){
        int n, m; cin >> n >> m;

        int answer = 0;

        for (int i = 0; i < n; ++i) {
            int u; cin >> u;

            if (i == 0) {
                answer += u;
            } else {
                int t = min(m / i, u);
                answer += t;
                m -= t * i;
            }
        }

        cout << answer << endl;
    }

    return 0;
}