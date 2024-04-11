#include<bits/stdc++.h>
using namespace std;
int n,m,h,ma[100],l,r,x,ans;

int main(){
    cin>>n>>h>>m;
    for(int i=1;i<=n;i++)
    ma[i]=h;
    for(int i=1;i<=m;i++){
        cin>>l>>r>>x;
        for(int j=l;j<=r;j++){
            ma[j]=min(ma[j],x);
        }
    }
    for(int i=1;i<=n;i++){
        ans+=(ma[i]*ma[i]);
    }
    cout<<ans<<endl;
}