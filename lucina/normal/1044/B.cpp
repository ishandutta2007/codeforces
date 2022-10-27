#include<bits/stdc++.h>
using namespace std;
int T,n,u,v,x,ma,best,d[1005];
vector<int> a[1002],b,c;
bool sp[1002];
void dfs(int nod,int pa){
    if(sp[nod]){
        if(d[nod]<ma)
            ma=d[nod],best=nod;
    }
    for(auto i:a[nod]){
        if(i!=pa){
            d[i]=d[nod]+1;
            dfs(i,nod);
        }
    }
    return;
}

int main(){
    scanf("%d",&T);
    while(T--){
        memset(sp,false,sizeof(sp));
        for(int i=1;i<=1000;i++)
            a[i].clear();
        b.clear();c.clear();
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        scanf("%d",&x);
        for(int i=1;i<=x;i++){
            scanf("%d",&u);
            b.push_back(u);
            sp[u]=true;
        }
        scanf("%d",&x);
        for(int i=1;i<=x;i++){
            scanf("%d",&u);
            c.push_back(u);
        }
        ma=1005,best=-1;
        printf("B %d\n",c[0]);
        fflush(stdout);
        scanf("%d",&x);
        d[x]=0;
        dfs(x,0);
        printf("A %d\n",best);
        fflush(stdout);
        scanf("%d",&x);
        for(auto i:c){
            if(i==x){
                printf("C %d\n",best);
                fflush(stdout);
                sp[0]=true;
                break;
            }
        }
        if(!sp[0]){
            printf("C -1\n");
            fflush(stdout);
        }
    }
}