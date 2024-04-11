#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

char word[N];
map<pair<string, int>, int> M;
int dp[N][2];

int main() {

    scanf("%s", &word[1]);
    int n = strlen(word + 1);
    dp[n + 1][0] = dp[n + 1][1] = true;
    vector<string> ans;
    int begPos = 6;
    for (int i = n - 1; i >= begPos; i--) {

        string s1 = "";
        s1 += word[i];
        s1 += word[i + 1];
        if (((!M.count({s1, i + 2}) || M[{s1, i + 2}] != i + 2) && dp[i + 2][0]) || dp[i + 2][1]) {
            ans.push_back(s1);
            dp[i][0] = true;
        }

        M[{s1, i}] = i;
        if (i < n - 1) {
            s1 += word[i + 2];
            if (((!M.count({s1, i + 3}) || M[{s1, i + 3}] != i + 3) && dp[i + 3][1]) || dp[i + 3][0]) {
                ans.push_back(s1);
                dp[i][1] = true;
            }

            M[{s1, i}] = i;
        }
    }
    sort(ans.begin(), ans.end());

    int ile = 0;
    for (int j = 0; j < ans.size(); j++) {
        if (j > 0 && ans[j] == ans[j - 1]) continue;
        ile++;
    }
    printf("%d\n", ile);
    for (int j = 0; j < ans.size(); j++) {
        if (j > 0 && ans[j] == ans[j - 1]) continue;
        string s = ans[j];
        for (int i = 0; i < s.size(); i++) {
            printf("%c", s[i]);
        }
        printf("\n");
    }

    return 0;
}