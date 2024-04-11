#include <bits/stdc++.h>
using namespace std;
void solve(){
    int N;
    cin>>N;
    int a[N];
    for(int i=0;i<N;i++)cin>>a[i];
    sort(a,a+N);
    int ans=0,cnt=0;
    for(int i=0;i<N;i++){
        cnt++;
        if(cnt==a[i]){
            ans++;
            cnt=0;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}