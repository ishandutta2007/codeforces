#include <bits/stdc++.h>

using namespace std;
const int N = 105;
char tab[N];
int n;
int main() {
    scanf("%d", &n);
    scanf("%s", &tab[1]);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int pos = j;
            bool git = true;
            for(int k = 1; k <= 5; k++) {
                if(pos > n || tab[pos] == '.') {
                    git = false;
                    break;
                }
                pos += i;
            }
            if(git == true) {
                printf("yes\n");
                return 0;
            }
        }
    }
    printf("no\n");
    return 0;
}