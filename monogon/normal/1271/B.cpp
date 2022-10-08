
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 205;
int n;
string s;
bool b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        b[i] = (s[i] == 'B');
        cnt ^= b[i];
    }
    if(cnt == 1 && n % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> v;
    for(int i = 0; i < n; i++) {
        if(b[i] != cnt) {
            b[i + 1] = !b[i + 1];
            v.push_back(i);
        }
    }
    cout << v.size() << endl;
    for(int x : v) {
        cout << (x + 1) << " ";
    }
    cout << endl;
}