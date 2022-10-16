#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int>M;
int A[100001],f[100001],n,c,s;
main(){
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>A[i],f[i]=f[i-1]+A[i],s+=A[i],M[A[i]]++;
        if(i>c)if(s-=A[i-c],!--M[A[i-c]])M.erase(A[i-c]);
        if(i>=c)f[i]=min(f[i],f[i-c]+s-M.begin()->first);
    }
    cout<<f[n];
}