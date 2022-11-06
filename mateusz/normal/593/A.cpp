#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;
string s[N];

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            int totalLength = 0;
            for (int k = 0; k < n; k++) {
                bool isGood = true;
                for (int l = 0; l < s[k].length(); l++) {
                    if (s[k][l] != i + 97 && s[k][l] != j + 97) {
                        isGood = false;
                        break;
                    }
                }
                if (isGood == true) {
                    totalLength += s[k].length();
                }
            }
            ans = max(ans, totalLength);
        }
    }

    cout << ans << endl;

    return 0;
}