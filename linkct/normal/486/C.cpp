#include <cstdio>
const int MAXN = 100005;

char str[MAXN];
int n, p;

inline int min(int a, int b){return a > b ? b : a;}
inline int abs(int x){return x >= 0 ? x : -x;}
inline int getDist(char a, char b){
    return min(abs(a - b), min(abs(a + 26 - b), abs(b + 26 - a)));
}
int main(){
    int i, ans = 0, maxPos = 0, minPos;
    scanf("%d%d%s", &n, &p, str + 1);
    minPos = n + 1;
    for(i = 1; i <= n >> 1; ++ i)
        if(str[i] != str[n - i + 1]){
            ans += getDist(str[i], str[n - i + 1]);
            if(i > maxPos) maxPos = i;
            if(i < minPos) minPos = i;
        }
    if(minPos == n + 1){
        printf("0\n");
        return 0;
    }
    if(p > (n >> 1) + (n & 1)) p = n - p + 1;
    if((n & 1) && p == ((n >> 1) + (n & 1))){
        printf("%d\n", ans + p - minPos);
        return 0;
    }
    if(abs(p - minPos) > abs(maxPos - p)) ans += abs(maxPos - p);
    else ans += abs(p - minPos);
    printf("%d\n", ans + maxPos - minPos);
    return 0;
}