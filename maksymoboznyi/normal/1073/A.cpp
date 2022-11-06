#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const int N = 1e5 + 5;
const long long inf = 2e18;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i + 1 < s.size(); i++)
    if (s[i] != s[i + 1]) {
        cout << "YES\n";
        cout << s[i] << s[i + 1];
        return 0;
    }
    cout << "NO";
    return 0;
}