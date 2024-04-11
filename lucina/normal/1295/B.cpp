#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
char s[nax];
int n, pre[nax], x;

int main(){
    int T;
    for(cin >> T; T -- ;){
        map<int, int> ss;
        scanf("%d %d", &n, &x);
        scanf("%s", s + 1);
        for(int i = 1 ;i <= n ;i ++){
            pre[i] = pre[i - 1] + (s[i] == '0' ? 1 : -1);
            ss[pre[i]] ++;
        }
        int bal = pre[n];
        if(bal == 0 && ss.count(x)){
            printf("-1\n");
            continue;
        }
        if(bal == 0){
            printf("%d\n", ss[x] + (x == 0));
            continue;
        }
        long long ans = 0;
        for(auto it : ss){
            int y = it.first;
            if((x - y) % bal == 0 && (x - y) / bal >= 0){
                ans += it.second;
            }
        }
        printf("%lld\n", ans + (x == 0));
    }
}
/*
    Good Luck
        -Lucina
*/