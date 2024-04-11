#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    long long int a,b,c,d;cin>>a>>b>>c>>d;
    if(n*(a+b)<(c-d) || n*(a-b)>c+d){
        cout<<"No"<<"\n";
    }else{
        cout<<"Yes"<<"\n";
    }
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