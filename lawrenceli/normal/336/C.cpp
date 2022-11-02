#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100005;
const int MAXL = 30;

int n;
int a[MAXN];
vector<int> v;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=MAXL; i>=0; i--) {
        v.clear();
        int x=(1<<(MAXL+1))-1;
        for (int j=0; j<n; j++) {
            if (a[j]&(1<<i)) {
                x&=a[j];
                v.push_back(a[j]);
            }
        }
        if (v.empty()) continue;
        bool ok=1;
        for (int j=0; j<i; j++) {
            if (x&(1<<j)) {
                ok=0;
                break;
            }
        }
        if (!ok) continue;
        cout << v.size() << endl;
        for (int i=0; i<v.size(); i++) {
            cout << v[i];
            if (i<v.size()-1) cout << ' ';
            else cout << endl;
        }
        return 0;
    }
    cout << n << endl;
    for (int i=0; i<n; i++) {
        cout << a[i];
        if (i<n-1) cout << ' ';
        else cout << endl;
    }
}