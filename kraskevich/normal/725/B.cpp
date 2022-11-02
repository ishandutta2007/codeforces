#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    map<char, int> delta{{'a', 4}, {'b', 5}, {'c', 6}, {'f',1}, {'e',2}, {'d',3}};
    string s;
    cin >> s;
    char c = s.back();
    ll n = stoll(s.substr(0, s.length() - 1));
    if (n % 4 == 0) 
        n = (n / 2 - 1) * 6 + (n - 3);
    else if (n % 4 == 1)
        n = n / 2 * 6 + (n - 1);
    else if (n % 4 == 2)
        n = n / 2 * 6 + (n - 1);
    else if (n % 4 == 3)
        n = (n / 2 - 1) * 6 + (n - 3);
    cout << n + delta[c] << endl;
    return 0;
}