#include<bits/stdc++.h>
using namespace std;
string go(string s, int x) {
    s += x + '0';
    while (!s.empty() && s.back() == '0') s.pop_back();
    reverse(s.begin(), s.end());
    return s;
}
string my_to_string(int64_t x) {
    string res;
    while (x > 0) {
        res += '0' + x % 2;
        x /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int64_t cx, cy;
    cin >> cx >> cy;
    string x = my_to_string(cx), y = my_to_string(cy);
    if (x == y) {
        return !printf("YES\n");
    }
    vector <string> tst;
    tst.push_back(go(x, 0));
    tst.push_back(go(x, 1));
    for (int i = tst.size() - 1 ; i >= 0 ; -- i) {
        tst.push_back(go(tst[i], 0));
        tst.push_back(go(tst[i], 1));
    }
    for (string s : tst) {
        for (int i = 0 ; i + int(s.size()) <= int(y.size()); ++ i)
           {
                bool ok = true;
                for (int j = 0 ; j < int(s.size()) ; ++ j)
                    ok &= (s[j] == y[i + j]);
                if (!ok) continue;
                for (int j = 0 ; j < y.size() ; ++ j) {
                    if (j < i || j >= i + int(s.size())) {
                        ok &= (y[j] == '1');
                    }
                }
                if (ok) {
                    return !printf("YES\n");
                }
           }
        }
    puts("NO");

}