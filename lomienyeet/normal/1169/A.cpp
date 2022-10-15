#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,x,b,y;
    cin>>n>>a>>x>>b>>y;
    while(a!=x&&b!=y){
        a++;
        b--;
        if(a>n)a-=n;
        if(!b)b+=n;
        if(a==b){
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
}