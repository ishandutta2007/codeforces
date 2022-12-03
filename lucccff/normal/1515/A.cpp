#include <bits/stdc++.h>
using namespace std;

int a[10010],b[100];

int main(){
    int i,j,k,l,m,n,t,f,x;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>x;
        l=0;
        f=0;
        memset(a,0,sizeof(a));
        a[0]=-1;
        cin>>k;
        f=0;
        b[0]=k;
        for(j=1;j<n;j++) {
            cin>>b[j];
        }
        k=0;
        for(j=0;j<n;j++) {
            k+=b[j];
            if (k==x) {
                break;
            }
        }
        if (j!=n) {
            if (j==n-1) {
                cout<<"NO\n";
            }
            else {
                cout<<"YES\n";
                for(k=0;k<j;k++) {
                    cout<<b[k]<<' ';
                }
                cout<<b[j+1]<<' '<<b[j]<<' ';
                for(k=j+2;k<n;k++) {
                    cout<<b[k]<<' ';
                }
                cout<<endl;
            }
        }
        else {
            cout<<"YES\n";
            for(k=0;k<n;k++) cout<<b[k]<<' ';
            cout<<endl;
        }
    }
    return 0;
}