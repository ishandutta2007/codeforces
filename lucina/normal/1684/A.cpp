#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    
    for (cin >> T ; T -- ;) {
        string s;
        cin >> s;
        if (s.size() == 2) cout << s[1] << '\n';
        else cout << *min_element(s.begin(), s.end()) << '\n';
    }
}