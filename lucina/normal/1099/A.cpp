#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a,b,x,y,z,w;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>a>>b>>x>>y>>z>>w;
    if(w>y){
        swap(x,z);
        swap(y,w);
    }
    while(b>y){
        a+=(b);
        b--;
    }
    a+=y;
    a=max(0,a-x);
    y--;
    while(y>w){
        a+=y;
        y--;
    }
    a+=w;
    a=max(0,a-z);
    w--;
    while(w>0){
        a+=w;
        w--;
    }
    cout<<a;
}