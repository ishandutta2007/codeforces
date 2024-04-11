#include<bits/stdc++.h>
using namespace std;
long long t,i,m,n;
 
int main(){
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m;
        if(n%m) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}