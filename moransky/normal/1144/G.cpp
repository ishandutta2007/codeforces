#include <cstdio>
#include <iostream>
using namespace std;
const int N = 200010;
int n, a[N], ans[N];
//nb
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i);
    
    int A = -1, B = 1e9;
    //AB
    for(int i = 1; i <= n; i++){
        if(a[i] <= A && a[i] >= B) { puts("NO"); return 0; }
        if(a[i] > A && a[i] < B){
            if(i != n){
                if(a[i] < a[i + 1]) A = a[i];
                else B = a[i], ans[i] = 1;
            }
        }else if(a[i] > A){
            A = a[i];
        }else if(a[i] < B){
            B = a[i];
            ans[i] = 1;
        }
    }
    puts("YES");
    for(int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}