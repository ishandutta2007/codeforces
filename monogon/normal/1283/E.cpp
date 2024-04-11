
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n;
int x[N];
bool b[N];

int getmax() {
    fill(b, b + N, false);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(!b[x[i] - 1]) {
            b[x[i] - 1] = true; cnt++;
        }else if(!b[x[i]]) {
            b[x[i]] = true; cnt++;
        }else if(!b[x[i] + 1]) {
            b[x[i] + 1] = true; cnt++;
        }
    }
    return cnt;
}
int getmin() {
    fill(b, b + N, false);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(!b[x[i]] && !b[x[i] - 1] && !b[x[i] + 1]) {
            b[x[i] + 1] = true;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x, x + n);
    cout << getmin() << " " << getmax() << endl;
}