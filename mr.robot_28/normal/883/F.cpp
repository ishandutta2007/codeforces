#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    set < string > Q;
    while (t--) {
        string s;
        cin >> s;
        int find = 1;
        while (find) {
            find = 0;
            for (int i = 0; i < (int)s.size(); ++i) {
                if (s[i] == 'u') {
                    string to = "";
                    for (int j = 0; j < i; ++j) to += s[j];
                    to += "oo";
                    for (int j = i + 1; j < s.size(); ++j) to += s[j];
                    s = to;
                    find = 1;
                    break;
                }
                if (i + 1 < (int)s.size() && s[i] == 'k' && s[i + 1] == 'h') {
                    string to = "";
                    for (int j = 0; j < s.size(); ++j) if (j != i) to += s[j];
                    s = to;
                    find = 1;
                    break;
                }
            }
        }
        Q.insert(s);
    }
    cout << Q.size();
    return 0;
}