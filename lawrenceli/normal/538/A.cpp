#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    string s;
    cin >> s;
    int n = s.length();
    for (int i=0; i<n; i++)
        for (int j=i+1; j<=n; j++) {
            string t = "";
            for (int k=0; k<i; k++) t += s[k];
            for (int k=j; k<n; k++) t += s[k];
            if (t == "CODEFORCES") {
                cout << "YES";
                return 0;
            }
        }
    cout << "NO";
}