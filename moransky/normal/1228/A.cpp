#include <cstdio>
#include <iostream>
using namespace std;
int l, r, cnt[10];
bool inline check(int x) {
    for (int i = 0; i < 10; i++)
        cnt[i] = 0;
    
    while(x) {
        if(cnt[x % 10]) return false;
        cnt[x % 10]++;
        x /= 10;
    }
    return true;
}
int main() {
    scanf("%d%d", &l, &r);
    for (int i = l; i <= r; i++) {
        if(check(i)) {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}