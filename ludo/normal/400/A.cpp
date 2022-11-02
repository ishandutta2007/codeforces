#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

pair<int, int> ways[6] = {
    make_pair(1, 12), make_pair(2, 6), make_pair(3, 4),
    make_pair(4, 3), make_pair(6, 2), make_pair(12, 1)
};
int nwins, wins[6];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        string str;
        cin >> str;
        nwins = 0;
        for(int j = 0; j < 6; j++) {
            bool valid = false;
            for(int k = 0; k < ways[j].second; k++) {
                bool f = true;
                for (int l = k; l < 12; l += ways[j].second) {

//                    if (i==0) cerr << j << " " << k << " " << l << endl;

                    if (str[l] == 'O') {
//                        cerr << "wrong" << endl;
                        f = false;
                        break;
                    }
                }
                if (f) {
//                    cerr << "valid" << endl;
                    valid = true;
                    break;
                }
            }
            if (valid) {
                wins[nwins++] = j;
            }
        }
        cout << nwins;
        for(int j = 0; j < nwins; j++) {
            cout << " " << ways[wins[j]].first << "x" << ways[wins[j]].second;
        }
        cout << endl;
    }

    return 0;
}