#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int t,l,r,d;
int main(){
    cin>>t;
    while(t--){
        cin>>l>>r>>d;
        if(d<l){
            cout<<d<<'\n';
        }
        else{
            printf("%d\n",(r/d+1)*d);
        }
    }


}