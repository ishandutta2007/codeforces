#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,a,b,c,counter=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a>>b>>c;
        if(a==b and b==c and a==1){
            counter++;
            a=0;
            b=0;
        }
        else if(a==c and a!=b and a==1){
            counter++;
        }
        else if(a==b and b!=c and a==1){
            counter++;
        }
        else if(a!=b and b==c and b==1){
            counter++;
        }
    }
    cout<<counter<<"\n";
    return 0;
}