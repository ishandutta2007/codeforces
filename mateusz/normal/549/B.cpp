#include <bits/stdc++.h>

using namespace std;
const int N = 105;
bool added[N];
char know[N][N];
int ile[N];
int n;

void dodaj(int w) {
     added[w] = 1;
     for(int j = 1; j <= n; j++) {
             if(know[w][j] == '1')
                           ile[j]--;
     }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
            scanf("%s", &know[i][1]);
    }
    for(int i = 1; i <= n; i++) scanf("%d", &ile[i]);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
            int git = 1;
            for(int j = 1; j <= n; j++) {
                    if(ile[j] == 0) {
                              dodaj(j);
                              git = 0;
                              ans++;
                              break;
                    }
            }
            if(git)
                   break;
    }
    printf("%d\n", ans);
    for(int i = 1; i <= n; i++) {
            if(added[i]) printf("%d ", i);
    }
    return 0;
    }