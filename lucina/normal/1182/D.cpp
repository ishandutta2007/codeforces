#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,u,v,d[maxn],deg[maxn],r[maxn],ma,best,p[maxn];
vector<int> a[maxn];
vector<int> b[maxn];
vector<int> candidate;
vector<int> s;
bool ok;
bool satan;
bool cheat;
void dfs(int nod,int pa,int dep){
    p[nod]=pa;
    if(dep>ma){
        ma=dep;
        best=nod;
    }
    for(int i:a[nod]){
        if(i!=pa){
            dfs(i,nod,dep+1);
        }
    }
    return;
}
void Lucina(int nod,int pa,int dep){
    for(auto i:a[nod]){
        if(i!=pa&&deg[i]==2){
            Lucina(i,nod,dep+1);
        }
        if(i!=pa&&deg[i]==1&&dep!=ma/2-1){
            if(!satan){
                candidate.push_back(i);
                satan=true;
            }
        }
        if(i!=pa&&deg[i]==1&&dep==ma/2-1&&i!=best&&i!=candidate[1]){
            s.push_back(i);
        }
    }
    return;
}
void diameter(){
    ma=0;
    dfs(1,0,0);
    int tt=best;ma=0;
    dfs(tt,0,0);
    candidate.push_back(best);
    candidate.push_back(tt);
    for(int i=1;i<=ma/2;i++){
        best=p[best];
    }
    candidate.push_back(best);
    Lucina(best,0,0);
    if(!satan&&!s.empty())candidate.push_back(s[0]);
    return;
}
void dfs2(int nod,int pa){
    if(r[d[nod]]==0){
        r[d[nod]]=deg[nod];
    }
    else{
        if(r[d[nod]]!=deg[nod])
            ok=false;
    }
    for(int i:a[nod]){
        if(i!=pa){
            d[i]=d[nod]+1;
            dfs2(i,nod);
        }
    }
    return;
}
void test(int nod){
    if(nod<=0)return;
    d[nod]=0;
    memset(r,0,sizeof(r));
    ok=true;
    dfs2(nod,-1);
    if(ok){
        printf("%d\n",nod);
        exit(0);
    }
    return;
}

int main(){
    scanf("%d",&n);
    if(n<=3){
        return !printf("1");
    }
     cheat=false;
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    diameter();
    for(int i:candidate){
        test(i);
    }
    printf("-1");
}