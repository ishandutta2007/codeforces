
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    set<string> se;
    while(n--) {
        string s;
        cin >> s;
        if(se.count(s)) {
            cout << "YES\n";
        }else cout << "NO\n";
        se.insert(s);
    }
}