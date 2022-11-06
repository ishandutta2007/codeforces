#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

const char vowels[] = {'A', 'E', 'I', 'O', 'U', 'Y'};

char word[N];

bool isVowel(char c) {
    for (int i = 0; i < 6; i++) {
        if (c == vowels[i]) {
            return true;
        }
    }
    return false;
}

int main() {

    scanf("%s", &word[1]);

    int last = 0;
    int l = strlen(word + 1);
    int ans = 0;
    for (int i = 1; i <= l; i++) {
        if (isVowel(word[i])) {
            ans = max(ans, i - last);
            last = i;
        }
    }
    ans = max(ans, l + 1 - last);

    printf("%d\n", ans);

    return 0;
}