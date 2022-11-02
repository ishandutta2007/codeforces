#include<bits/stdc++.h>
using namespace std;
long long n,m,k,l,i,check1,check2;
 
int main() {
    cin>>n>>m;
    if(m>0 && m<=n && n!=1)
    {
    check1=(m-1);
    check2=(n-m);
    if(check1>=check2) cout<<m-1;
    else cout<<m+1;
    }
    else if(n==1 && m==1)
    {
        cout<<1;
    }
    else if(m<=0)
    {
        cout<<1;
    }
    else cout<<n;
    return 0;
}