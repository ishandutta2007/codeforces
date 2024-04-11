#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,b;
    cin>>N;
    string a;
    for(int i=0;i<N;i++){
        cin>>a;
        b=a.length();
        if(b>10){
            cout<<a[0]<<b-2<<a[b-1]<<"\n";
        }
        else{
            cout<<a<<"\n";
        }
    }
    return 0;
}