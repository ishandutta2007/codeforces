#include <cstdio>
#include <iostream>
using namespace std;
const int N = 200010;
int n, ans[N];
char s1[N], s2[N];
int main(){
    scanf("%d%s%s", &n, s1 + 1, s2 + 1);
    for(int i = n; i; i--){
        ans[i] += s1[i] + s2[i] - 2 * 'a';
        ans[i - 1] += ans[i] / 26;
        ans[i] %= 26;
    }
    for(int i = 0; i <= n; i++){
        if(ans[i] & 1) ans[i + 1] += 26;
        ans[i] /= 2;
    }
    for(int i = 1; i <= n; i++)
        putchar(ans[i] + 'a');
    return 0;
}