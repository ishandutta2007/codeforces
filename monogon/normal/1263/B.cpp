
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 10;
int t, n;
bool dif[N];
set<pair<string, int>> s;
string str[N];
set<int> dig;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        s.clear();
        for(int i = 0; i < 10; i++) dig.insert('0' + i);
        for(int i = 0; i < n; i++) {
            dif[i] = false;
            cin >> str[i];
            s.emplace(str[i], i);
        }
        for(auto p : s) {
            dig.erase(p.first[0]);
        }
        int k = 0;
        auto it = s.begin();
        while(next(it) != s.end()) {
            it++;
            if(prev(it)->first == it->first) {
                dif[it->second] = true;
                k++;
            }
        }
        cout << k << endl;
        for(int i = 0; i < n; i++) {
            if(dif[i]) {
                str[i][0] = *dig.begin();
                dig.erase(dig.begin());
            }
            cout << str[i] << endl;
        }
    }
}