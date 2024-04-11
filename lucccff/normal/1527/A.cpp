#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        long long x=1;
        while(x<=n)x<<=1;
        x>>=1;
        x--;
        cout<<x<<endl;
    }
    return 0;
}