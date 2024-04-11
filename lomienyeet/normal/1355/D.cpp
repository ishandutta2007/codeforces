#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,S;
    cin>>N>>S;
    if(S<2*N){
        cout<<"NO"<<"\n";
    }
    else{
        cout<<"YES"<<"\n";
        for(int i=0;i<N-1;i++){
            cout<<"1"<<" ";
        }
        cout<<S-(N-1)<<"\n";
        cout<<S/2<<"\n";
    }
}