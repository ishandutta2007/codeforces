# include <iostream>
# include <cstdio>
# include <cstring>
# include <map>
# include <set>

using namespace std;

map<int,int> e1, e2;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        set<int> e;
        for(char c:s) e.insert(c);
        if(e.size() > 2) continue;
        if(e.size() == 2) {
            char l = *e.begin();
            char r = *e.rbegin();
            e2[l*128+r] += s.length();
        } else {
            char l = *e.begin();
            e1[l] += s.length();
        }
    }
    int ans = 0;
    for(char c = 'a'; c <= 'z'; ++c) {
        for(char d = 'a'; d <= 'z'; ++d) if(d!=c) {
            int tmp = 0;
            if(e1.count(c)) tmp += e1[c];
            if(e1.count(d)) tmp += e1[d];
            if(e2.count(c*128+d)) tmp += e2[c*128+d];
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
}