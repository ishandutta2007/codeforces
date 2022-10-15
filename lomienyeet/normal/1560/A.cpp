#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int wa[12269];
    for(int i=1,g=1;i<12269;){
        if(g%3&&g%10!=3){
            wa[i]=g;
            i++;
        }
        g++;
    }
    while(t--){
        int x;
        cin>>x;
        cout<<wa[x]<<"\n";
    }
}