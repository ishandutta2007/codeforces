#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    int j = 1;
    if(n%4!=0){
        cout<<"NO"<<"\n";
        return;
    }
    cout<<"YES"<<"\n";
    for(int i=0;i<n/4;i++){
        cout<<2*j<<" "<<2*j+2<<" ";
        j+=3;
    }
    j=1;
    for(int i=0;i<n/4;i++){
        cout<<2*j-1<<" "<<2*j+3<<" ";
        j+=3;
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
	//cout<<"Case #"<<i+1<<": ";
       	solve();
    }   
}