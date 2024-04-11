#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    int x,y;
    cin>>x>>y;
    if(!x&&!y)cout<<"0\n";
    else{
        int z=x*x+y*y;
        cout<<1+(floor(sqrt(z))!=ceil(sqrt(z)))<<"\n";
    }
}
signed main(){
    int t;
    cin>>t;
    while(t--)eat();
}