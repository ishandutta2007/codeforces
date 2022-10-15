#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin>>n;
    int l=1,r=n-1,z=0;
    while(l<r){
        int mid=(l+r+1)>>1;
        cout<<"+ "<<n-mid<<"\n";
        fflush(stdout);
        int x;
        cin>>x;
        if(x==z){
            l+=n-mid;
            r=n-1;
        }
        else{
            l=0;
            r-=mid;
        }
        z=x;
    }
    cout<<"! "<<n*z+l<<"\n";
    fflush(stdout);
}