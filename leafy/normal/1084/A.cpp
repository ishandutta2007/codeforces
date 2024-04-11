#include<bits/stdc++.h>
using namespace std;
int n;
int a[105];
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0x7f7f7f7f;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++) 
            cnt+=2*a[j]*(abs(i-j)+j+i-2);
        if(cnt<ans) ans=cnt;
    }
    cout<<ans;
    return 0;
}