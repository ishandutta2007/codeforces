#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int N=100005;

int n,m,a[N],phi[N];

int getphi(int mm){
    if(mm==1) return 0;
    int ph=1;
    for(int x=2;x*x<=mm;x++){
        if(mm%x!=0) continue;
        int cnt=0;
        while(mm%x==0){
            if(cnt==0) ph*=(x-1);
            else ph*=x;
            ++cnt;
            mm/=x;
        }
    }
    if(mm!=1) ph*=(mm-1);
    return ph;
}

int power(int x,int v,int p){
    int ans=1;
    for(;v;v>>=1,x=(ll)x*x%p)
        if(v&1) ans=(ll)ans*x%p;
    return ans;
}

int work(int l,int r,int *c){
    if(*c==1) return 0;
    if(a[l]==1) return 1;
    if(l==r){
        return a[l]%(*c);
    }
    int aim=min(r,l+7);
    rep(i,l+1,aim) if(a[i]==1){
        aim=i;
        break;
    }
    ll tot=a[aim];
    int flag=0;
    dep(i,aim-1,l+1){
        if(tot>30 || a[i]>=*(c+1)){
            flag=1;
            break;
        }
        ll ft=1,xx=a[i];
        for(;tot;tot>>=1,xx=xx*xx){
            if(xx>=*(c+1)) break;
            if(tot&1) ft=ft*xx;
            if(ft>=*(c+1)) break;
        }
        if(ft>=*(c+1) || xx>=*(c+1)){
            flag=1;
            break;
        }
        tot=ft;
    }
    if(flag)
        return power(a[l],work(l+1,r,c+1)+(*(c+1)),*c);
    else
        return power(a[l],tot,*c);
}

int main(){
    //printf("%d\n",power(2,20,100000000));
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",a+i);
    phi[0]=m;
    rep(i,1,200){
        phi[i]=getphi(phi[i-1]);
        //printf("%d\n",phi[i]);
        //return 0;
        if(phi[i]==0) break;
    }
    /*
    rep(i,1,100){
        printf("%d ",phi[i]);
        if(phi[i]==0){
            puts("");
            break;
        }
    }
    */
    //printf("%d\n",power(2,phi[1],m));
    
    int q;
    scanf("%d",&q);
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==y){
            printf("%d\n",a[x]%m);
        }else if(m==1){
            printf("%d\n",0);
        }else
            {
                printf("%d\n",work(x,y,phi));
        }
    }
}