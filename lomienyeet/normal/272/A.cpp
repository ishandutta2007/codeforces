#include <iostream>
using namespace std;
int main(){
    int n,s=0,res=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        s+=a;
    }
    for(int i=1;i<6;i++){
        if((s+i)%(n+1)==1)res++;
    }
    cout<<5-res<<"\n";
}