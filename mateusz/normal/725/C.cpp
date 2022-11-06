#include <bits/stdc++.h>

using namespace std;

const int N = 30;

char word[N];
int ans[N][2];
int poss[N];

int main() {

    scanf("%s", &word[1]);
    int n = 13;
    int repeatingPos = -1;
    int len = -1;
    for (int i = 1; i <= 27; i++) {
        word[i] -= 65;
        if (poss[word[i]] != 0) {
            repeatingPos = poss[word[i]];
            len = i - poss[word[i]];
        }
        poss[word[i]] = i;
    }

    if (len == 1) {
        printf("Impossible\n");
        return 0;
    }
    
    if (len % 2 == 1) {
        int pos = len / 2 + 1;
        int in = repeatingPos;
        for (int i = pos; i >= 1; i--) {
            ans[i][0] = word[in];
            in++;
        }
        for (int i = 1; i < pos; i++) {
            ans[i][1] = word[in];
            in++;
        }
        in = repeatingPos - 1;
        for (int i = pos + 1; i <= n; i++) {
            if (in == 0) {
                break;
            }
            ans[i][0] = word[in];
            in--;
        }
        if (in > 0) {
            for (int i = n; i >= 1; i--) {
                ans[i][1] = word[in];
                in--;
                if (in == 0) {
                    break;
                }
            }
        }
        in = repeatingPos + len + 1;
        for (int i = pos; i <= n; i++) {
            if (in > 27) {
                break;
            }
            ans[i][1] = word[in];
            in++;
        }
        if (in <= 27) {
            for (int i = n; i >= 1; i--) {
                ans[i][0] = word[in];
                in++;
                if (in > 27) {
                    break;
                }
            }
        }
    } else {
        int pos = len / 2;
        int in = repeatingPos;
        for (int i = pos; i >= 1; i--) {
            ans[i][0] = word[in];
            in++;
        }
        for (int i = 1; i <= pos; i++) {
            ans[i][1] = word[in];
            in++;
        }
        in = repeatingPos - 1;
        for (int i = pos + 1; i <= n; i++) {
            if (in == 0) {
                break;
            }
            ans[i][0] = word[in];
            in--;
        }
        if (in > 0) {
            for (int i = n; i >= 1; i--) {
                ans[i][1] = word[in];
                in--;
                if (in == 0) {
                    break;
                }
            }
        }
        in = repeatingPos + len + 1;
        for (int i = pos + 1; i <= n; i++) {
            if (in > 27) {
                break;
            }
            ans[i][1] = word[in];
            in++;
        }
        if (in <= 27) {
            for (int i = n; i >= 1; i--) {
                ans[i][0] = word[in];
                in++;
                if (in > 27) {
                    break;
                }
            }
        }
    }
    for (int j = 0; j < 2; j++) {
        for (int i = 1; i <= 13; i++) {
            printf("%c", ans[i][j] + 65);
        }
        printf("\n");
    }
    return 0;
}