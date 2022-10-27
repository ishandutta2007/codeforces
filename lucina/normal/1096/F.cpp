#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mod=998244353;
int n,bit[maxn],p[maxn],ct,q,gt[maxn];
bool vis[maxn];
int get(int idx){
    int sum=0;
    while(idx>0){
        sum+=bit[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
void update(int idx,int val){
    while(idx<=n){
        bit[idx]+=val;
        idx+=(idx&(-idx));
    }
    return;
}
inline int add(int a,int b){
    return a+b>=mod?a+b-mod:a+b;
}
inline int sub(int a,int b){
    return a<b?a-b+mod:a-b;
}
inline int mul(int a,int b){
    return (int)((1ll*a*b)%mod);
}
inline int power(int a,int b){
    int res=1;
    while(b>0){
        if(b&1)
            res=mul(res,a);
        a=mul(a,a);
        b>>=1;
    }
    return res;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
        if(p[i]==-1){
            ct++;
        }
        else
            vis[p[i]]=true;
    }
    q=0;
    for(int i=n;i>=1;i--){
        gt[i]=q;
        q+=(vis[i]?0:1);
    }
    int ans=0;
    for(int i=n;i>=1;i--){
        if(p[i]!=-1){
        ans=add(ans,get(p[i]-1));
        update(p[i],1);
        }
    }

    int inv=power(ct,mod-2);
    ans=add(ans,mul(mul(ct,ct-1),power(4,mod-2)));
    int l=0;
    for(int i=1;i<=n;i++){
        if(p[i]==-1){
            l++;
        }
        else{
            ans=add(ans,mul(mul(l,gt[p[i]]),inv));
        }
    }
    int r=0;
    for(int i=n;i>=1;i--){
        if(p[i]==-1){
            r++;
        }
        else{
            ans=add(ans,mul(r,mul(ct-gt[p[i]],inv)));
        }
    }
    printf("%d\n",ans);
}