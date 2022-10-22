#include <iostream>
using namespace std;
int t;
int main(){
    cin>>t;
    while(t--){
        unsigned long long x,y;
        cin>>x>>y;
        if(x-y>=2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}