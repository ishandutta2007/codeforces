
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 105, T = 1445;
int n, l[N], r[N], mode, cnt;
ll p1, p2, p3, t1, t2, energy;
bool mouse[T];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        for(int j = l[i]; j < r[i]; j++) {
            mouse[j] = true;
        }
    }
    mode = 1;
    cnt = energy = 0;
    for(int i = l[0]; i < r[n - 1]; i++) {
        if(mouse[i]) {
            mode = 1;
            cnt = 0;
            energy += p1;
        }else if(mode == 1) {
            energy += p1;
            cnt++;
            if(cnt == t1) {
                mode = 2;
                cnt = 0;
            }
        }else if(mode == 2) {
            energy += p2;
            cnt++;
            if(cnt == t2) {
                mode = 3;
                cnt = 0;
            }
        }else if(mode == 3) {
            energy += p3;
        }
    }
    cout << energy << endl;
}