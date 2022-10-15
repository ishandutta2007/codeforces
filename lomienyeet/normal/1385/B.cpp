#include <bits/stdc++.h>
using namespace std;
void solve(){
    int N;
    cin>>N;
    int a[N*2];
    for(int i=0;i<2*N;i++){
        cin>>a[i];
    }
    int cnt[N+1];
    for(int i=0;i<=N;i++)cnt[i]=0;
    for(int i=0;i<2*N;i++){
        for(int j=1;j<=N;j++){
            if(a[i]==j and cnt[j]==0)cnt[j]++;
            else if(a[i]==j and cnt[j]==1)a[i]=0;
        }
    }
    for(int i=0;i<2*N;i++){
        if(a[i]!=0)cout<<a[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}