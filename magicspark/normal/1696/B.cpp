#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];int ans=0;
        for(int i=1;i<=n;i++)if(a[i-1]==0&&a[i])ans++;
        cout<<min(2,ans)<<endl;
    }
}