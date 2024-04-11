#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int t, n, m;
vector<int> a[N];

bool isCorrect(int x, int y) {
    for (int i=0; i<n; i++)
        swap(a[i][x], a[i][y]);
    bool cor = 1;
    for (int i=0; i<n; i++)
        for (int j=1; j<m; j++)
            if (a[i][j] < a[i][j-1])
                cor = 0;
    for (int i=0; i<n; i++)
        swap(a[i][x], a[i][y]);
    return cor;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            a[i].resize(m);
            for (int j=0; j<m; j++) {
                cin >> a[i][j];
            }
        }
        
        pair<int,int> shouldSwap = {0,0};
        for (int i=0; i<n; i++) {
            for (int j=1; j<m; j++) {
                if (a[i][j] < a[i][j-1]) {
                    //     l j     k
                    // 1 2 6 5 5 5 3 7 8
                    int l=j-1;
                    while (l > 0 && a[i][l-1] == a[i][j-1])
                        l--;
                    for (int k=j; k<m; k++) {
                        if (a[i][k] <= a[i][j])
                            shouldSwap = {l, k};
                    }
                    break;
                }
            }
        }
        if (isCorrect(shouldSwap.fi, shouldSwap.se)) {
            cout << shouldSwap.fi+1 << " " << shouldSwap.se+1 << endl;
        } else {
            cout << "-1" << endl;
        }
    }
}