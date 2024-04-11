#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long a[100010][20];

int main(){
    long long i,j,k,l,m,n,t,s,x,p,q;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n>>k;
        s=1;
        for(j=0;j<k;j++) {
            s=(s*n)%MOD;
        }
        cout<<s<<endl;
    }
    return 0;
}