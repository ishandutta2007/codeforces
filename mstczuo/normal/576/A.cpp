# include <bits/stdc++.h>
using namespace std;

bool p[1200];

int main() {
    int n; cin >> n;
    vector<int> ans;
    memset(p, true, sizeof(p));
    for(int i = 2; i <= n; ++i) {
        if(p[i]) {
            for(int j = i; j <= n; j *= i) 
                ans.push_back(j);
            for(int j = i * i; j <= n; j += i)
                p[j] = false;
        }
    }
    cout << ans.size() << endl;
    for(auto u:ans) cout << u << ' ';
    cout << endl;
}