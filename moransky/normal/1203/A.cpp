#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 205;
int n, a[N << 1];
bool check(){
    for(int i = 1; i <= n; i++){
        if(abs(a[i] - a[i + 1]) != 1) continue;
        bool flag = true;
        int  f = a[i] < a[i + 1] ? 1 : -1;
        for(int j = i; j < i + n - 1; j ++)
            if(a[j] + f != a[j + 1]) { flag = false; break;  }
        if(flag) return true;
    }
    return false;
}
int main(){
    int q; scanf("%d", &q); 
    while(q--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", a + i), a[i + n] = a[i];

        if(n == 1 || check()) puts("YES");
        else puts("NO");
    }
    return 0;
}