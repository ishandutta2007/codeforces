#include<cstdio>
const int N=200002;
int T,i,n,cnt,op,p[N],t;
char a[N],b[N];
void calc(int k,int l,int r){
    if(k==0)
        return;
    if(b[k]==(a[r]^t)){
        if(l<r)
            calc(k-1,l,r-1);
        else
            calc(k-1,l,r+1);
    }
    else{
        if(a[l]!=a[r])
            p[++cnt]=1;   
        p[++cnt]=k;
        t^=1;
        if(l<r)
            calc(k-1,r,l+1);
        else
            calc(k-1,r,l-1);
    }

}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%s%s",&n,a+1,b+1);
        cnt=0;
        t=0;
        calc(n,1,n);
        printf("%d ",cnt);
        for(i=1;i<=cnt;i++)
            printf("%d ",p[i]);
        printf("\n");
    }
}