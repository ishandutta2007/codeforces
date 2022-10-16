#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 100005;
struct HP{
    int p[N], len;
    HP() {
        len = 0;
        memset(p, 0, sizeof p);
    }
};
HP operator + (HP a, HP b){
    HP c; int len = max(a.len, b.len);
    int t = 0;
    for(int i = 1; i <= len || t; i++){
        t += a.p[i] + b.p[i];
        c.p[++c.len] = t % 10;
        t /= 10;
    }
    return c;
}
HP min(HP a, HP b){
    if(a.len != b.len) return a.len > b.len ? b : a;
    for(int i = a.len; i; i--)
        if(a.p[i] > b.p[i]) return b;
        else if(a.p[i] < b.p[i]) return a;
    return a;
}
void print(HP &a){
    for(int i = a.len; i; i--)
        printf("%d", a.p[i]);
    puts("");
}
char s[N];
int n, st[N], tot;
HP ans;

HP get(int l, int r){
    HP res;
    for(int i = r; i >= l; i--)
        res.p[++res.len] = s[i] - '0';
    return res;
}

int main(){

    for(int i = 1; i <= 100000; i++)
        ans.p[++ans.len] = 9;

    scanf("%d%s", &n, s + 1); 

    for(int i = 1; i < n; i++){
        if(s[i + 1] != '0') st[++tot] = i;
    }

    int loc = lower_bound(st + 1, st + 1 + tot, n >> 1) - st;
    int l = max(1, loc - 10), r = min(tot, loc + 10);
    for(int t = l; t <= r; t++){
        int i = st[t];
        ans = min(ans, get(1, i) + get(i + 1, n));
    }
    print(ans);
    return 0;
}