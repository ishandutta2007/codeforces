
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
string s, t;
int sa, ta;
vector<int> type1, type2, pts;
vector<pair<int, int> > sw;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s >> t;
    for(int i = 0; i < n; i++) {
        sa += (s[i] == 'a');
        ta += (t[i] == 'a');
        if(s[i] == 'a' && t[i] == 'b') {
            type1.push_back(i);
        }else if(s[i] != t[i]) {
            type2.push_back(i);
        }
        if(s[i] != t[i]) {
            pts.push_back(i);
        }
    }
    if((sa + ta) % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }
    while(type1.size() >= 2) {
        int a = type1.back();
        type1.pop_back();
        int b = type1.back();
        type1.pop_back();
        sw.push_back({a, b});
    }
    if(type1.size()) {
        type2.push_back(type1[0]);
        sw.push_back({type1[0], type1[0]});
    }
    while(type2.size() >= 2) {
        int a = type2.back();
        type2.pop_back();
        int b = type2.back();
        type2.pop_back();
        sw.push_back({a, b});
    }
    cout << sw.size() << endl;
    for(auto p : sw) {
        cout << (p.first + 1) << " " << (p.second + 1) << endl;
    }
}