#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,k,a[maxn],ct;

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    reverse(a+1,a+1+n);
    int lft=m,tot=k;
    for(int i=1;i<=n;i++){
        if(a[i]<=tot){
            if(tot==k)lft--;
            tot-=a[i];
            ct++;
        }
        else{
            if(lft==0)return !printf("%d\n",ct);
            lft--;tot=k;ct++;
            if(tot>=a[i])
                tot-=a[i];
            else
                return !printf("%d\n",ct);
        }
    }
    printf("%d\n",ct);
}