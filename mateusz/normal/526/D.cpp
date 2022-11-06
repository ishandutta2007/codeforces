#include <bits/stdc++.h>

using namespace std;
const int N = 1000005;
int P[N];
char slowo[N];
int n, k;

int main() {
    scanf("%d %d", &n, &k);
    scanf("%s", &slowo[1]);
    P[0] = -1;  
    int t = 0;
    printf(k == 1? "1": "0");
    for(int i = 2; i <= n; i++) {
        while(t >= 0 && slowo[t + 1] != slowo[i]) {
            t = P[t];
        }
        t++;
        P[i] = t;
        int okres = i - P[i];
        int mx = i / k;
        int mn = i / (k + 1);
        if(i % (k + 1) != 0)
            mn++;
        if(mx / okres != (mn - 1) / okres) {
            printf("1");
        } else {
            printf("0");
        }
    }
    
    return 0;
}