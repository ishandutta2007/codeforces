#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t,f,s;
    int a[100010],b[100010],c[100010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<n;j++) {
            cin>>a[j];
            b[j+1]=0;
        }
        f=0;
        for(j=0;j<n;j++) if (a[j]<=j) {
            f=1;
            break;
        }
        if (f) {
            cout<<-1<<endl;
            continue;
        }

        k=1;
        b[a[0]]=1;
        c[0]=a[0];
        for(j=1;j<n;j++) {
            if (a[j]!=a[j-1]) {
                c[j]=a[j];
                b[a[j]]=1;
            }
            else {
                while(b[k]==1) k++;
                b[k]=1;
                c[j]=k;
            }
        }
        
        for(j=0;j<n;j++) {
            cout<<c[j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}