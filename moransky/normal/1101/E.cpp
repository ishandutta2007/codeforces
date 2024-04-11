#include <cstdio>
#include <iostream>
using namespace std;
const int N = 500010;
int n, a = 0, b = 0;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        char ch; cin >> ch;
        if(ch == '+'){
            int x, y; scanf("%d%d", &x, &y);
            if(x > y) swap(x, y);
            a = max(a, x);
            b = max(b, y);
        }else{
            int h, w; scanf("%d%d", &h, &w);
            if(h > w) swap(h, w);
            if(a <= h && b <= w) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}