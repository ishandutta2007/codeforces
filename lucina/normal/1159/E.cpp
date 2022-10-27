#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int t,p[maxn],b[maxn],n,timer;
vector<int> a[maxn];
void dfs(int x){
    for(int i:a[x]){
        timer--;
        p[i]=timer;
        dfs(i);
    }
    return;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n+1;i++)
            a[i].clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
            if(b[i]==-1)b[i]=i+1;
            a[b[i]].push_back(i);
        }
        timer=n+1;
        dfs(n+1);
        vector<int> q;bool r=true;
        for(int i=n;i>=1;i--){
           while(!q.empty()&&p[q.back()]<p[i])
                q.pop_back();
           if((q.empty()&&b[i]!=n+1)||(!q.empty()&&q.back()!=b[i])){
            printf("-1\n");
            r=false;
            break;
           }
           q.push_back(i);
        }
        if(r){
            for(int i=1;i<=n;i++)
                printf("%d ",p[i]);
            printf("\n");
        }
    }
}