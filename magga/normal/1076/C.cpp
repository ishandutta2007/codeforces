#include<bits/stdc++.h>
using namespace std;
void solve(){
    long double d;cin>>d;
    if(d<4 && d!=0){
        cout<<"N"<<"\n";
        return;
    }
    long double p = sqrt(d*d-4*d);
    cout<<setprecision(15)<<"Y"<<" "<<(d+p)/2<<" "<<(d-p)/2<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
   cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}