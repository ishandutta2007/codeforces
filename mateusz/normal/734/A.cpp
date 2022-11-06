#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;
char word[N];

int main() {

    scanf("%d", &n);
    scanf("%s", word);

    int as = 0, ds = 0;
    for (int i = 0; i < n; i++) {
        if (word[i] == 'A') {
            as++;
        } else {
            ds++;
        }
    }

    if (as == ds) {
        printf("Friendship\n");
    } else if (as > ds) {
        printf("Anton\n");
    } else {
        printf("Danik\n");
    }

    return 0;
}