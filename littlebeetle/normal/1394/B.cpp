#include<cstdio>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;
const int N=1000002;
struct Uzi{
    int w,t;
};
vector<Uzi>e[N];
int n,m,i,j,k,Ans,a,b,d;
ll p[N],c[10][10];
ll Rand(){
    return 1ull*rand()*N*N+1ull*rand()*N+rand();
}
void init(){
    scanf("%d%d%d",&n,&m,&k);
    while(m--){
        scanf("%d%d%d",&a,&b,&d);
        e[a].push_back((Uzi){d,b});
    }
    for(i=1;i<=n;i++)
        p[i]=Rand();
}
bool cmp(Uzi u,Uzi v){
    return u.w<v.w;
}
void dfs(int i,ll s){
    if(i==k+1){
        Ans+=s==0;
        return;
    }
    for(int j=0;j<i;j++)
        dfs(i+1,s^c[i][j]);
}
void work(){
    for(i=1;i<=n;i++){
        sort(e[i].begin(),e[i].end(),cmp);
        for(j=0;j<e[i].size();j++)
            c[e[i].size()][j]^=p[i]^p[e[i][j].t];
    }
    dfs(1,0);
    printf("%d\n",Ans);
}
int main(){
    init();
    work();
    return 0;
}