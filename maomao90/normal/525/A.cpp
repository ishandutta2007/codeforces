#include <cstdio>

using namespace std;

int n;
int cnt[30];
int ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        char key, door; scanf(" %c", &key); scanf(" %c", &door);
        cnt[key - 'a']++;
        if (cnt[door - 'A'] == 0) {
            ans++;
        } else cnt[door - 'A']--;
    }
    printf("%d\n", ans);
}