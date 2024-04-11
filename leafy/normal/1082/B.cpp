#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n;
char s[N];
int f[N],g[N];
int main(){
    scanf("%d\n",&n);
    scanf("%s",s+1);
    int ans=0,sum=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='G') g[i]=g[i-1]+1,sum++;
        else g[i]=0;
        ans=max(ans,g[i]);
    }
    for(int i=n;i>=1;i--){
        if(s[i]=='G') f[i]=f[i+1]+1;
        else f[i]=0;
    }
    for(int i=2;i<n;i++){
        if(s[i]=='S') {
            if(sum==g[i-1]+f[i+1]){
                ans=max(ans,g[i-1]+f[i+1]);
            }else ans=max(ans,g[i-1]+f[i+1]+1);
        }
    }
    cout<<ans;
    return 0;
}