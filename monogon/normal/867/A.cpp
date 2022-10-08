
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << (s[0] == 'S' && s.back() == 'F' ? "YES" : "NO") << '\n';
}