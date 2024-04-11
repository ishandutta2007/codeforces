#include <bits/stdc++.h>
using namespace std;

int K, S;

void draw(int s, int n)
{
    for (int i=1;i<n;i++) for (int j=i+1;j<=n;j++){
        if (i == 1 && j == 2 ||
            i == 1 && j == n ||
            (i%2 == 1 && i+1 == j)) continue;
        printf("%d %d\n", s+i-1, s+j-1);
    }
}

int main()
{
    cin >> K;
    if (!(K&1)){ puts("NO"); return 0; }
    puts("YES");
    if (K == 1){ puts("2 1\n1 2"); return 0; }
    S = K+2;
    printf("%d %d\n", S<<1, S*K);
    draw(1, S); printf("%d %d\n", 1, S+1);
    draw(S+1, S);
}