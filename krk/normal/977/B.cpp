#include <bits/stdc++.h>
using namespace std;

int n;
string s;
map <string, int> M;

int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i + 1 < n; i++)
        M[s.substr(i, 2)]++;
    int mx = 0;
    string b;
    for (auto it: M)
        if (it.second > mx) {
            mx = it.second;
            b = it.first;
        }
    cout << b << endl;
    return 0;
}