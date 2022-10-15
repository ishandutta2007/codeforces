#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int sum=0,maxi=0;
    for(int i=0,x;i<n;i++){
        cin>>x;
        sum+=x;
        maxi=max(maxi,x);
    }
    if(sum&1)cout<<"T\n";
    else if(maxi*2>sum)cout<<"T\n";
    else cout<<"HL\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}