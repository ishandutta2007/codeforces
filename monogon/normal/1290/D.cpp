#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1030;
int n, k;
bool b[N];

void reset() {
    cout << 'R' << endl;
}

bool query(int i) {
    string c;
    cout << "? " << i << endl;
    cin >> c;
    if(c == "E") assert(false);
    return c == "Y";
}
void answer(int cnt) {
    cout << "! " << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    if(k == 1) {
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                reset();
                query(i);
                if(query(j)) {
                    b[j] = true;
                }
            }
        }
    }else {
        int m = n / (k / 2);
        for(int dif = 1; dif < m; dif++) {
            for(int r = 0; r < dif && r + dif < m; r++) {
                reset();
                for(int i = r; i < m; i += dif) {
                    for(int j = 1; j <= k / 2; j++) {
                        if(query(i * (k / 2) + j)) {
                            b[i * (k / 2) + j] = true;
                        }
                    }
                }
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        cnt += !b[i];
    }
    answer(cnt);
}