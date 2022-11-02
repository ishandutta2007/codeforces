#include<cstdio>
const int N=100002;
int T,n,a[N],ok,i;
bool Q(int l,int r,int p){
    if(l>=r)return 1;
    int k,o;
    for(k=r;a[k]!=p;k--);
    for(o=k;o<r;o++)
        if(a[o]+1!=a[o+1])
            return 0;
    return Q(l,k-1,a[r]+1);
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",a+i);
        printf("%s\n",Q(1,n,1)?"Yes":"No");
    }
}