#include<bits/stdc++.h>
using namespace std;
void solve(){
    int N;
    cin>>N;
    int a[N+1],f[N+1];
    int l=1,r=N;
    for(int i=1;i<=N;i++){
        cin>>a[i];
        f[a[i]]=i;
    }
    for(int i=N;i>=1;i--){
        if(f[i]==l)l++;
        else if(f[i]==r)r--;
        else{
            cout<<"YES\n"<<l<<" "<<f[i]<<" "<<r<<"\n";
            return;
        }
    }
    cout<<"NO\n";
}
int main(){
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}