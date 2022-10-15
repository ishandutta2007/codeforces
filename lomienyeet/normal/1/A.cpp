#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int a,b,c;
    cin>>a>>b>>c;
    long long int v;
    if((a%c)==0){
        v=a/c;
    }
    else{
        v=round((a/c)+0.5);
    }
    long long int h;
    if((b%c)==0){
        h=b/c;
    }
    else{
        h=round((b/c)+0.5);
    }
    if(v*h==0){
        cout<<1<<"\n";
    }
    else{
        cout<<v*h<<"\n";
    }
}