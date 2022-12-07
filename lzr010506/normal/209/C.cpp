#include <cstdio>
#include <cstring>
const int N=1000010;
struct bs{
    bs *fa;
    bs *genf(){
        return fa==0?this:fa=fa->genf();
    }
    int ds,val;
}p[N];
int main(){
    int n,m,ans=0;
    scanf("%d%d",&n,&m);
    memset(p,0,sizeof(p));
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b),a--,b--;
        p[a].ds++,p[b].ds++;
        if(p[a].genf()!=p[b].genf())
            p[a].genf()->fa=p[b].genf();
    }
    for(int i=0;i<n;i++){
        if(p[i].ds%2){
            ans++;
            p[i].genf()->val++;
        }
    }
    ans/=2;
    int i;
    for(i=1;i<n;i++) if(p[i].ds&&p[i].genf()!=p[0].genf()) break;
    if(i==n){
        printf("%d\n",ans);
        return 0;
    }
    if(p[0].genf()->val==0) ans++;
    for(int i=1;i<n;i++){
        if(p[i].ds==0) continue;
        if(p[i].genf()!=p[0].genf()){
            if(p[i].genf()->val==0) ans++;
            p[i].genf()->fa=p;
        }
    }
    printf("%d\n",ans);
    return 0;
}