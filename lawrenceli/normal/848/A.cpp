#include <bits/stdc++.h>

using namespace std;

int num[500];

int main() {
    for (int i = 1; i < 500; i++) num[i] = i * (i - 1) / 2;
    int k; cin >> k;
    string s = "";
    char c = 'a';
    while (k) {
        assert(c <= 'z');
        int a = upper_bound(num, num + 500, k) - num - 1;
        for (int i = 0; i < a; i++) s += c;
        c++;
        k -= num[a];
    }
    if (s == "") s = "a";
    cout << s << '\n';
}