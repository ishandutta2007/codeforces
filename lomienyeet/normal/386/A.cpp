#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int maxi=-1,sec,ptr;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        if(x>maxi){
            sec=maxi;
            maxi=x;
            ptr=i;
        }
        if(x>sec&&x<maxi)sec=x;
    }
    cout<<ptr<<" "<<sec<<"\n";
}