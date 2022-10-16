#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int x,y,z;
        cin>>x>>y>>z;
        cout<<min(x,max(y+z-x+1,1))<<' '<<min(x,y-1+z)<<endl;
    }
}