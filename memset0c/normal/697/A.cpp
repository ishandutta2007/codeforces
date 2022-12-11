#include <bits/stdc++.h>
using namespace std;

int t,s,x;

int main(){
    scanf("%d%d%d", &t, &s, &x);
    if (x < t) { puts("NO"); return 0; }
    if ((!((x - t) % s) || !((x - t - 1) % s)) && x != t + 1)
        puts("YES");
    else
        puts("NO");
    return 0;
}