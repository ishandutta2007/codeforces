#include <bits/stdc++.h>
using namespace std;

int N, K;

int main()
{
    cin >> N >> K;
    int s = N*N - N*N/2;
    if (K > s){ puts("NO"); return 0; }
    puts("YES");
    for (int i=1;i<=N;i++,puts("")) for (int j=1;j<=N;j++){
        if (!((i+j)&1)){
            putchar(K ? 'L' : 'S');
            if (K) K--;
        }
        else putchar('S');
    }
}