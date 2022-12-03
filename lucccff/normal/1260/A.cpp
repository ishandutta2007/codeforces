#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t,s;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>k;
        l=k/n;
        m=k%n;
        s=0;
        for(j=0;j<m;j++) {
            s+=(l+1)*(l+1);
        }
        for(j=m;j<n;j++) {
            s+=l*l;
        }
        cout<<s<<endl;
    }
    return 0;
}