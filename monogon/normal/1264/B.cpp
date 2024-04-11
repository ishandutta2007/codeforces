
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int a[4], b[4];
int arr[N];
int n;

bool func(int f, bool l) {
    for(int i : {0, 1, 2, 3}) b[i] = a[i];
    for(int i = 0; i < n; i++) {
        if(f < 0 || f > 3 || b[f] == 0) return false;
        arr[i] = f;
        b[f]--;
        if(l) {
            if(f > 0 && b[f - 1] > 0) {
                f--;
            }else {
                f++;
            }
        }else {
            if(f < 3 && b[f + 1] > 0) {
                f++;
            }else {
                f--;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i : {0, 1, 2, 3}) {
        cin >> a[i];
        n += a[i];
    }
    for(int f : {0, 1, 2, 3}) {
        for(int l : {0, 1}) {
            if(func(f, l)) {
                cout << "YES" << endl;
                for(int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}