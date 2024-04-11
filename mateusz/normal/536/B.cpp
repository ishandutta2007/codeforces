#include <bits/stdc++.h>

using namespace std;
const int N = 1000005, M = 1000000007;
int p, m, n;
char slowo[N];
int P[N];
int zlicz[N];
int sub[N];
int main() {
    scanf("%d %d", &p, &m);
    scanf("%s", &slowo[1]);
    int n = strlen(slowo + 1);
    P[0] = -1;  
    int t = 0;
    for(int i = 2; i <= n; i++) {
        while(t >= 0 && slowo[t + 1] != slowo[i]) {
            t = P[t];
        }
        t++;
        P[i] = t;
    }
    for(int i = 1; i <= m; i++) {
        scanf("%d", &sub[i]);
    }
    if(m == 0) {
        int wynik = 1;
        for(int i = 1; i <= p; i++) {
            wynik = (long long)wynik * 26 % M;
        }
        printf("%d\n", wynik);
        return 0;
    }
    int x = P[n];
    while(x > 0) {;
        zlicz[x]++;
        x = P[x];
    }
    int wolnePola = sub[1] - 1;
    for(int i = 2; i <= m; i++) {
        if(sub[i - 1] + n - 1 >= sub[i]) {
            int d = sub[i - 1] + n - sub[i];
            if(zlicz[d] == false) {
                printf("0\n");
                return 0;
            }
        } else {
            wolnePola += sub[i] - 1 - (sub[i - 1] + n - 1);
        }
    }
    wolnePola += p - (sub[m] + n - 1);
    int wynik = 1;
    for(int i = 1; i <= wolnePola; i++) {
        wynik = (long long)wynik * 26 % M;
    }
    printf("%d\n", wynik);
    return 0;
}