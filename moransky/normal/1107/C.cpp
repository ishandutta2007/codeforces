#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 200010;
int n, k, a[N];
LL ans = 0;
char s[N];
priority_queue<int, vector<int>, greater<int> > q;
int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    scanf("%s", s + 1);
    for(int i = 1; i <= n; i++){
        if(s[i] != s[i - 1]){
            while(!q.empty()) ans += q.top(), q.pop();
            q.push(a[i]);
        }else{
            q.push(a[i]);
        }
        while(q.size() > k) q.pop();
    }
    while(!q.empty()) ans += q.top(), q.pop();
    printf("%lld\n", ans);
    return 0;
}