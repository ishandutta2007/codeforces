#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, t;
char word1[N], word2[N], retWord[N];

int main() {

    scanf("%d %d", &n, &t);
    scanf("%s %s", &word1[1], &word2[1]);

    int diffPos = 0;
    for (int i = 1; i <= n; i++) {
        if (word1[i] != word2[i]) {
            diffPos++;
        }
    }

    if (diffPos > 2 * t) {
        printf("-1\n");
        return 0;
    }

    int changedWithA = 0;
    int changedWithB = 0;
    for (int i = 1; i <= n; i++) {
        if (word1[i] != word2[i]) {
            if (changedWithB < changedWithA) {
                changedWithB++;
                retWord[i] = word1[i];
            } else {
                changedWithA++;
                retWord[i] = word2[i];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (word1[i] != word2[i]) {
            if ((changedWithB < changedWithA || (changedWithA == changedWithB && diffPos > 1)) && retWord[i] == word2[i] && changedWithB < t) {
                for (int j = 'a'; j <= 'z'; j++) {
                    if (j != word2[i] && j != word1[i]) {
                        retWord[i] = j;
                        break;
                    }
                }
                changedWithB++;
            } else if ((changedWithA < changedWithB || (changedWithA == changedWithB && diffPos > 1)) && retWord[i] == word1[i] && changedWithA < t) {
                for (int j = 'a'; j <= 'z'; j++) {
                    if (j != word1[i] && j != word2[i]) {
                        retWord[i] = j;
                        break;
                    }
                }
                changedWithA++;
            }
            diffPos--;
        }
    }
    if (changedWithA != changedWithB) {
        printf("-1\n");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (word1[i] != word2[i]) {
            continue;
        }

        if (changedWithA < t) {
            for (int j = 'a'; j <= 'z'; j++) {
                if (j != word1[i]) {
                    retWord[i] = j;
                    break;
                }
            }
            changedWithA++;
            changedWithB++;
        } else {
            retWord[i] = word1[i];
        }

    }
    if (changedWithA < t) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        printf("%c", retWord[i]);
    }

}