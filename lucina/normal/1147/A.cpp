#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,k,a[maxn],c[maxn],ct,la[maxn],f[maxn],ans;
//check every [a,b]
//a-> how many b valid
//if there is one point there is no
//a in first part and no b in second half

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
    scanf("%d",&a[i]);
    for(int i=1;i<=k;i++){
        if(f[a[i]]==0)
        f[a[i]]=i;
        la[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(la[i]==0){
            ans+=(i!=1&&i!=n)?3:2;
        }
        else{
            if(i>1&&la[i-1]<=f[i])
                ans++;
            if(i<n&&la[i+1]<=f[i])
                ans++;
        }
    }
    printf("%d\n",ans);
}