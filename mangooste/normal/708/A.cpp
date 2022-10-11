#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> using vec = vector<T>;
template<typename A, typename B = A> using pr = pair<A, B>;
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()
#define ar array

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string s;
    cin >> s;
    int i = 0;
    while (i < len(s) && s[i] == 'a')
        i++;
    int j = i;
    while (j < len(s) && s[j] != 'a')
        j++;
    if (i == len(s))
        i--;
    for (int k = 0; k < len(s); k++)
        if (k < i || k >= j)
            cout << s[k];
        else
            cout << char('a' + (s[k] - 'a' + 25) % 26);
    cout << '\n';
}