#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
const int N = 100010;
int n, l[N], r[N];
PII a[N];
int main(){
    int T; scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d%d", l + i, r + i);
            a[i].first = l[i];
            a[i].second = r[i];
        }
        sort(a + 1, a + 1 + n);
        int rr = a[1].second, loc = 0;
        for(int i = 2; i <= n; i++){
            if(a[i].first <= rr)
                rr = max(rr, a[i].second);
            else { loc = rr; break; }
        }
        if(!loc) printf("-1");
        else for(int i = 1; i <= n; i++)
            if(r[i] <= rr) printf("1 ");
            else printf("2 ");
        puts("");
    }
    return 0;
}