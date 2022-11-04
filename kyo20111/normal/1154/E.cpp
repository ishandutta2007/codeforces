#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,arr[202020],chk[202020],pl[202020],pr[202020],fl;
priority_queue<pair<int,int>> pq;
int l(int a){
    if(pl[a] == a) return a;
    return pl[a]=l(pl[a]);
}
int r(int a){
    if(pr[a] == a) return a;
    return pr[a]=r(pr[a]);
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++) pq.push({arr[i],i});
    for(int i=1;i<=n+1;i++) pl[i]=pr[i]=i;

    while(!pq.empty()){
        int cur=pq.top().second,nxt;
        pq.pop();

        if(chk[cur]) continue;
        chk[cur]=1+fl;
        fl=!fl;
        pl[cur]=l(cur-1);
        pr[cur]=r(cur+1);
        nxt=pl[cur];

        for(int i=1;i<=m;i++){
                if(nxt <= 0) break;
                chk[nxt]=chk[cur];
                pl[nxt]=nxt-1;
                pr[nxt]=nxt+1;
                nxt=l(pl[nxt]);
        }

        nxt=pr[cur];
        for(int i=1;i<=m;i++){
                if(nxt > n) break;
                chk[nxt]=chk[cur];
                pl[nxt]=nxt-1;
                pr[nxt]=nxt+1;
                nxt=r(pr[nxt]);
        }
    }

    for(int i=1;i<=n;i++) printf("%d",chk[i]);
}