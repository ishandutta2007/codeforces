#include <iostream>
#pragma GCC optimize("Ofast,inline,unroll-loops")
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int arr[n+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    while(m--){
        int op,l,r,x;
        cin>>op>>l>>r>>x;
        if(op==1){
            for(int i=l;i<=r;i++)arr[i]=(arr[i]>x?arr[i]-x:arr[i]);
        }
        else{
            int ans=0;
            for(int i=l;i<=r;i++)ans+=(arr[i]==x);
            cout<<ans<<"\n";
        }
    }
}