#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n, chk[100100];
int main(){
    scanf("%d",&t);
    while(t--){
        queue<int> q;
        queue<pair<int, int>> l;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) chk[i] = 0;

        for(int i=1;i<=n;i++){
            int a; scanf("%d",&a);
            int fl = 0;
            while(a--){
                int b; scanf("%d",&b);
                if(!fl && !chk[b]){
                    chk[b] = 1;
                    fl = 1;
                }
            }
            if(!fl) q.push(i);
        }

        int fl = 0;
        for(int i=1;i<=n;i++){
            if(q.empty()) break;

            if(!chk[i]){
                l.push({q.front(), i});
                q.pop();
                fl = 1;
                break;
            }
        }

        if(fl){
            printf("IMPROVE\n");
            printf("%d %d\n",l.front().first,l.front().second);
        }else printf("OPTIMAL\n");
    }
}