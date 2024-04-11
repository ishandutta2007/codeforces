
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, a[N];
set<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a[0];
    cout << a[0] << endl;
    for(int i = 1; i <= n; i++) s.insert(i);
    s.erase(a[0]);
    for(int i = 1; i < n - 1; i++) {
        cin >> a[i];
        if(s.count(a[i])) {
            cout << a[i] << " " << a[i - 1] << endl;
            s.erase(a[i]);
        }else {
            cout << *prev(s.end()) << " " << a[i - 1] << endl;
            s.erase(prev(s.end()));
        }
    }
    cout << *prev(s.end()) << " " << a[n - 2] << endl;
}