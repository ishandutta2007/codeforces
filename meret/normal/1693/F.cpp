#include <algorithm>
#include <iostream>

using namespace std;

string reversed(const string& s) {
    string result = string();
    for (int i = 0; i < (int) s.length(); ++i) {
        result += char(int('0') + int('1') - int(s[(int) s.length() - i - 1]));
    }
    return result;
}

int last_pos[200005];

int go() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c1 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ++c1;
        }
    }
    int c0 = n - c1;
    if (c1 > c0) {
        s = reversed(s);
        swap(c0, c1);
    }
    if (c1 == 0) {
        return 0;
    }
    for (int i = 0; i <= n; ++i) {
        last_pos[i] = -1;
    }
    last_pos[0] = n;
    int dif = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '1') {
            --dif;
        } else {
            ++dif;
        }
        if (dif >= 0 && last_pos[dif] == -1) {
            last_pos[dif] = i;
        }
    }
    int first1 = 0;
    while (s[first1] != '1') {
        ++first1;
    }
    if (n - first1 == c1) {
        return 0;
    }
    int result = 0;
    while (c0 - first1 - c1 > 0) {
        ++result;
        first1 = (first1 + last_pos[c0 - first1 - c1]) / 2;
    }
    return result + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int d;
    cin >> d;
    while (d--) {
        cout << go() << "\n";
    }
}