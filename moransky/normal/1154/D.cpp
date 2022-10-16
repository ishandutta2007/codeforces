#include <cstdio>
#include <iostream>
using namespace std;
const int N = 200010;
int n, b, a, s[N], ans = 0;
int main(){
    scanf("%d%d%d", &n, &b, &a);
    for(int i = 1; i <= n; i++) {
        scanf("%d", s + i);
    }
    
    int e = a;
    int last = 0;
    for(int i = 1; i <= n; i++){
        if(s[i]) {
            if(a == e) a--;
            else if(b) b--, a++;
            else a--;
        }else{
            if(a) a--;
            else if(b) b--;
        }
        ans = i;
        if(a + b == 0) break;
        
    }
    printf("%d\n", ans);
    return 0;
}