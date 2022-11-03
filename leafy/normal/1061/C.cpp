#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=1e9+7;
int a[N],f[N];
int n;
inline void up(int x){
    if(x<=n) f[x]=(f[x]+f[x+1]+1)%M;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=n;i>=1;i--)
        for(int j=1;j*j<=a[i];j++){
            if(a[i]%j) continue;
            up(j);
            if(j*j!=a[i]) up(a[i]/j);
        }
    printf("%d",f[1]);
    return 0;
}