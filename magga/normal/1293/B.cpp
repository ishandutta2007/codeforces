#include<bits/stdc++.h>
using namespace std;
long double pre[100001]{0.0};
void pro(){
    pre[0]=0;
    for(long long int i =1;i<100001;i++){
        pre[i]=pre[i-1]+1.0/i;
    }
}
void solve(){
    long long int n;cin>>n;
    cout<<pre[n]<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pro();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}