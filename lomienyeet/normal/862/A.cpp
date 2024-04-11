#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c=0,d;
    cin>>a>>b;
    while(a--){
        cin>>d;
        if(d<b)c++;
        if(d==b)c--;
    }
    cout<<b-c<<"\n";
}