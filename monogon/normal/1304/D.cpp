
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n;
string s;
vector<int> v1, v2;

void out(vector<int> &v) {
    int m = *min_element(v.begin(), v.end());
    for(int x : v) {
        cout << (x - m + 1) << " ";
    }
    cout << endl;
}
vector<int> solve() {
    vector<int> v = {0};
    int r = 0;
    for(int j = 0; j < (int) s.length(); j++) {
        if(s[j] == '>') {
            int k = 1;
            while(j + k < (int) s.length() && s[j + k] == '<') k++;
            r -= k;
            v.push_back(r);
        }else {
            v.push_back(v.back() + 1);
        }
    }
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> s;
        v1 = solve();
        reverse(s.begin(), s.end());
        for(int i = 0; i < (int) s.length(); i++) {
            s[i] = (s[i] == '<' ? '>' : '<');
        }
        v2 = solve();
        reverse(v2.begin(), v2.end());
        out(v1);
        out(v2);
    }
}