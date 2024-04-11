#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string format(string s) {
    int p = s.length() - 1;
    while (p > 0 && s[p] == '0')
        p--;
    if (s[p] == '.')
        p--;
    string res = s.substr(0, p + 1);
    if (res == "")
        res = "0";  
    return res;
}


int main() {
    ios_base::sync_with_stdio(0);
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    int pos = s.find('.');
    int i = pos + 1;
    while (i < s.length() && s[i] < '5')
        i++;
    if (i == s.length() || t == 0) {
        cout << s << endl;
        return 0;
    }
    string res = s;
    int carry = 1;
    t--;
    int last = i;
    bool can_round = true;
    for (int j = i - 1; j >= 0; j--) {
        if (s[j] == '.') {
            can_round = false;
            continue;
        }
        int cur = s[j] - '0' + carry;
        res[j] = char(cur % 10 + '0');
        if (cur >= 10) {
            carry = 1;   
            continue;
        }
        if (res[j] < '5' || t == 0 || !can_round) {
            carry = 0;
            break;
        }
        last = j;
        carry = 1;
        t--;
    }
    for (int j = last; j < s.length(); j++)
        res[j] = '0';
    if (carry)
        res = "1" + res;
    cout << format(res) << endl;
    return 0;
}