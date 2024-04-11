
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
        for(int i = 0; i < n / (k / 2); i++) {
            for(int j = i + 1; j < n / (k / 2); j++) {
                reset();
                for(int l = 1; l <= k / 2; l++) {
                    if(query(i * (k / 2) + l)) {
                        b[i * (k / 2) + l] = true;
                    }
                }
                for(int l = 1; l <= k / 2; l++) {
                    if(query(j * (k / 2) + l)) {
                        b[j * (k / 2) + l] = true;
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