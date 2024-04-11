#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t,s;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>m;
        s=0;
        for(j=0;j<n;j++) {
            cin>>k;
            s+=k;
        }
        if (n==2||m!=n) cout<<-1<<endl;
        else {
            cout<<2*s<<endl;
            for(j=1;j<n;j++) cout<<j<<' '<<j+1<<endl;
            cout<<n<<' '<<1<<endl;
        }
    }
    return 0;
}