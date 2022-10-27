#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
string s;
int main () {
    int T;
    cin.tie(0)->sync_with_stdio(false);
    for (cin >> T ; T -- ;) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        string to_print;
        while (!s.empty() && s.back() == '1') {
            to_print.push_back(s.back());
            s.pop_back();
        }
        reverse(to_print.begin(), to_print.end());
        n = s.size();

        int pos = -1;

        for (int i = 0 ; i < n ; ++ i) {
            if (s[i] == '1') {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            cout << s << to_print << '\n';
        } else {
            for (int i = 0 ; i < pos ; ++ i)
                cout << '0';
            cout << '0';
            cout << to_print << '\n';
        }
    }
}
/*
    Leon is the best girl in A17.
*/