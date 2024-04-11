#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,k,p[maxn];
void msort(int l,int r){
    if(l==r)
        return;
    int mid=(l+r-1)>>1;
    if(k>0){
            k-=2;
        swap(p[mid],p[mid+1]);
        msort(l,mid);msort(mid+1,r);
    }
    return;
}

int main(){
    /*f[1]=1;
    for(int i=2;i<=100000;i++){
        mid=i>>1;
        f[i]=f[mid]+(f[i-mid])+1;
    }*/
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        p[i]=i;
    if((k+1)%2||k>2*n-1){
        printf("-1");
        return 0;
    }
    k--;
    msort(1,n);
   // bool fuck=true;
    for(int i=1;i<=n;i++){
            //cout<<"BUG\n",fuck=false;
        printf("%d ",p[i]);
        }
    /*if(fuck)
        printf("safe\n");*/
}