#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int N;
char A[MAXN];

int main()
{
    scanf("%s", A+1); N = strlen(A+1);
    bool ans = 0, sw = 0;
    for (int i=1;i<N;i++){
        if (A[i] == 'B' && A[i+1] == 'A'){
            if (sw) ans |= 1;
        }
        if (A[i] == 'A' && A[i+1] == 'B' && !sw)
            sw = 1, i++;
    }
    sw = 0;
    for (int i=1;i<N;i++){
        if (A[i] == 'A' && A[i+1] == 'B'){
            if (sw) ans |= 1;
        }
        if (A[i] == 'B' && A[i+1] == 'A' && !sw)
            sw = 1, i++;
    }
    puts(ans ? "YES" : "NO");
}