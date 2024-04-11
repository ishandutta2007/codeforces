
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, a;
set<int> now, day;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        if(now.empty()) {
            day.clear();
            v.push_back(i);
        }
        if(a > 0) {
            if(day.count(a)) {
                cout << -1 << endl;
                return 0;
            }
            now.insert(a);
            day.insert(a);
        }else {
            if(now.count(-a) == 0) {
                cout << -1 << endl;
                return 0;
            }
            now.erase(-a);
        }
    }
    if(now.empty()) {
        v.push_back(n);
    }else {
        cout << -1 << endl;
        return 0;
    }
    cout << v.size() - 1 << endl;
    for(int i = 1; i < v.size(); i++) {
        cout << v[i] - v[i - 1] << " ";
    }
    cout << endl;
}