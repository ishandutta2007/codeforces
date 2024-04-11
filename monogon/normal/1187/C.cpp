
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 1005;
int n, m, t, l, r;
bool b[MAX_N];
int arr[MAX_N];
vector<int> L, R;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> t >> l >> r;
        l--; r--;
        if(t == 1) {
            for(int j = l; j < r; j++) {
                b[j] = true;
            }
        }else {
            L.push_back(l);
            R.push_back(r);
        }
    }
    arr[0] = n;
    for(int i = 0; i < n; i++) {
        if(b[i]) {
            arr[i + 1] = arr[i];
        }else {
            arr[i + 1] = arr[i] - 1;
        }
    }
    for(int i = 0; i < L.size(); i++) {
        if(arr[R[i]] == arr[L[i]]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}