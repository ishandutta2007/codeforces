#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 110;
int n;
char s[N];
int main(){
    int T; scanf("%d", &T);
    while(T--){
        scanf("%d%s", &n, s + 1);
        bool flag = false;
        for(int i = 1; i <= n - 10; i++)
            if(s[i] == '8') flag = true;
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}