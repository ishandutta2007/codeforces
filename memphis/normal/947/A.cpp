#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
const int N=1000005;

int x2,p[N],prime[N],len,g[N];

int work2(int f){
    if(g[f]==0) return 0x3f3f3f3f;
    return (f/g[f]-1)*g[f]+1;
}

void work(int f){
    int ans=f;
    dep(i,len,1){
        if(prime[i]>=f) continue;
        if(f%prime[i]==0){
            int l=(f/prime[i]-1)*prime[i]+1;
            int r=f;
            rep(j,l,r)
                ans=min(ans,work2(j));
            break;
        }
    }
    printf("%d\n",ans);
    exit(0);   
}

int main(){
    scanf("%d",&x2);
    rep(i,2,x2-1){
        if(p[i]==0){
            p[i]=i;
            g[i]=0;
            prime[++len]=i;
        }
        for(int j=1;j<=len && prime[j]<=p[i] && prime[j]*i<=x2;++j){
            p[prime[j]*i]=prime[j];
            if(g[i]==0) g[prime[j]*i]=i;
            else g[prime[j]*i]=g[i];
        }
    }

    work(x2);
}