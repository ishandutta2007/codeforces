#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
using namespace std;

typedef long long ll;

int main() {
    ios :: sync_with_stdio(false);

    string s;
    cin >> s;

    int loc;
    ll sum = 0;
    for (int i=0; i<s.length(); i++)
        if (s[i] == '^') loc = i;

    for (int i=0; i<s.length(); i++)
        if (s[i] != '^' && s[i] != '=')
            sum += ll(loc - i) * (s[i] - '0');

    if (sum == 0) cout << "balance" << endl;
    else if (sum > 0) cout << "left" << endl;
    else cout << "right" << endl;

    return 0;
}