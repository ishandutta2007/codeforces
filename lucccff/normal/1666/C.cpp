#include<bits/stdc++.h>
int ri() {
    char ch = getchar(); int x = 0, f = 1;
    for(;ch < '0' || ch > '9'; ch = getchar())
        if(ch == '-')
            f = -1;
    for(;ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
    return x * f;
}
int a1, b1, a2, b2, a3, b3;
int Findzhong(int x, int y, int z) {
    if(x > y) std::swap(x, y);
    if(y > z) std::swap(y, z);
    if(x > y) std::swap(x, y);
    return y;
}
void Connect(int a, int b, int c, int d) {
    printf("%d %d %d %d\n", a, b, a, d);
    printf("%d %d %d %d\n", a, d, c, d);
}
int main() {
    a1 = ri(); b1 = ri();
    a2 = ri(); b2 = ri();
    a3 = ri(); b3 = ri();
    int a = Findzhong(a1, a2, a3), b = Findzhong(b1, b2, b3);
    puts("6");
    Connect(a1, b1, a, b);
    Connect(a2, b2, a, b);
    Connect(a3, b3, a, b);
    return 0;
}