#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

void loop() {
    int a, b; scanf("%d%d", &a, &b);
    printf("%d\n", (abs(a - b) + 9) / 10);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) loop();

    return 0;
}