#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 110;
int n;
char str[N];
bool judge(){
    for(int i = 1; i <= n / 2; i++)
        if(abs(str[i] - str[n - i + 1]) != 2 && abs(str[i] - str[n - i + 1]) != 0) return false;
    return true;
}
int main(){
    int T; scanf("%d", &T);
    while(T--){
        scanf("%d%s", &n, str + 1);
        if(judge()) puts("YES");
        else puts("NO");
    }
    return 0;
}