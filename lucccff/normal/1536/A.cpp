#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    long long i,j,k,l,m,n,t;
    int a[200],c[200];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        k=0;
        m=0;
        memset(c,0,sizeof(c));
        for(j=0;j<n;j++) {
            cin>>a[j];
            if (a[j]<0) {
                k=1;
            }
            c[a[j]]++;
            if (c[a[j]]>1) m++;
        }
        if (k==1){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n"<<101+m<<endl;
        for(j=0;j<=100;j++) {
            if (c[j]<1) c[j]=1;
            for(k=0;k<c[j];k++) {
                cout<<j<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}