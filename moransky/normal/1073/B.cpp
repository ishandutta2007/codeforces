#include <iostream>
#include <cstdio>
using namespace std;
const int N = 200010;
int n, a[N];

int main(){
    scanf("%d", &n);
    for(int i = 1, x; i <= n; i++) 
        scanf("%d", &x), a[x] = i;
    int dep = 0;
    for(int i = 1; i <= n; i++){
        int x; scanf("%d", &x);
        if(a[x] <= dep) printf("0 ");
        else printf("%d ", a[x] - dep), dep = a[x];
    }
    return 0;
}