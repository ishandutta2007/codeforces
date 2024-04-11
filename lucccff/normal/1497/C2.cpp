#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t,s;
    int b[100000];
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n>>k;
        l=n=n-k+3;
        for(j=3;j<k;j++) cout<<1<<' ';
        while ((l>4)&&(l%2==0)) l=l>>1;
        if (l%2!=0) cout<<n/l*(l-1)/2<<' '<<n/l*(l-1)/2<<' '<<n/l<<endl;
        else cout<<n/4<<' '<<n/4<<' '<<n/2<<endl;
    }
    return 0;
}