#include <iostream>
#include <cstdio>
using namespace std;
const int N = 110;
int n, a[N], cnt[N], tot = 0, tot2 = 0, num = 0, st[N], cnt2[2][N];
bool vis[N];
char ans[N];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i), cnt[a[i]]++;
    for(int i = 1; i <= 100; i++){
        if(cnt[i] == 1) tot++;
        if(cnt[i] > 2) tot2++;
    }
    if((tot & 1) && (tot2)) tot++;
    if(tot & 1) puts("NO");
    else{
        puts("YES"); tot >>= 1;
        for(int i = 1; i <= n; i++){
            if(cnt[a[i]] == 1){
                if(num < tot)
                    ans[i] = 'A', num++, cnt2[0][a[i]]++;
                else if(num < tot * 2) 
                    ans[i] = 'B', num++, cnt2[1][a[i]]++;
            }
        }
        for(int i = 1; i <= n; i++){
            if(cnt[a[i]] != 1){
                if(cnt[a[i]] == 2) ans[i] = 'A', cnt2[0][a[i]]++;
                else if(vis[a[i]]) ans[i] = 'A' + st[a[i]], cnt2[st[a[i]]][a[i]]++;
                else if(num < tot && (!vis[a[i]]))
                    ans[i] = 'A', vis[a[i]] = true, st[a[i]] = 1, num++, cnt2[0][a[i]]++;
                else if(num < tot * 2 && (!vis[a[i]])) 
                    ans[i] = 'B', st[a[i]] = 0, vis[a[i]] = true, num++, cnt2[1][a[i]]++;
                else ans[i] = 'A', cnt2[0][a[i]]++;
            }
            
        }
        
        for(int i = 1; i <= n; i++) printf("%c", ans[i]);
    }
    return 0;
}