#include<bits/stdc++.h>
using namespace std;
const int M=3e5+5;
const int N=1e7+5e6+5;
int n,g,a[M],b[N],p[N],m;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(i==1) g=a[i];
        g=__gcd(g,a[i]);
        m=max(m,a[i]);
    }
    for(int i=1;i<=n;i++){
        b[a[i]/g]++;
    }
    int ans=0,res=0;
    for(int i=2;i<=m;i++){
        if(p[i]==0){
             res=0;
            for(int j=i;j<=m;j+=i){
                p[j]=1;
                res+=b[j];
            }
        ans=max(ans,res);
        }
    }
    if(ans==0)
        printf("%d\n",-1);
    else
        printf("%d\n",n-ans);
}