#include <bits/stdc++.h>
using namespace std;
string a[5];
string s;
bool fin;
int main() {
    cin >> s;
    a[0] += "Danil";
    a[1] += "Olya";
    a[2] += "Slava";
    a[3] += "Ann";
    a[4] += "Nikita";
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 5; j++) {
            if (i + a[j].size() - 1 < s.size()) {
                bool mark = true;
                for (int k = 0; k < a[j].size(); k++) {
                    if (s[i + k] != a[j][k]) mark = false;
                }
                if (mark == true) {
                    if (fin) {
                        cout << "NO";
                        return 0;
                    }
                    else fin = true;
                }
            }
        }
    }
    if (fin) cout << "YES";
    else cout << "NO";
    return 0;
}