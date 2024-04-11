#include <cstdio>
#define Lovelive long long
int main() {
    Lovelive l, r, w;
    scanf("%lld%lld%lld", &l, &r, &w);
    bool flag = true;
    if(w == 1) return puts((l == 1 && r >= 1) ? "1" : "-1"), 0; // 
    for(Lovelive tmp = 1; tmp <= r && tmp > 0; tmp = ((r / w >= tmp) ? tmp * w : r + 1)) {
        if(tmp >= l && tmp <= r) {
            printf("%lld ", tmp);
            flag = false;
        }
    }
    if(flag) puts("-1");
    return 0;
}