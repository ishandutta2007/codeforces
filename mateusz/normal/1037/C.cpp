#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int n;
char A[N], B[N];

int main() {
    
    scanf("%d", &n);
    
    scanf("%s", &A[1]);
    scanf("%s", &B[1]);
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] != B[i]) {
            if (i + 1 <= n && A[i + 1] != A[i] && A[i + 1] != B[i + 1]) {
                swap(A[i], A[i + 1]);
                ans++;
            } else {
                ans++;
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}