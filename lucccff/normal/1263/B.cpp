#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t;
    int a[11],b[10];
    cin>>t;
    for(i=0;i<t;i++) {
        memset(b,0,sizeof(b));
        cin>>n;
        for(j=0;j<n;j++) {
            cin>>a[j];
        }
        m=0;
        for(j=0;j<n;j++) {
            for(k=j+1;k<n;k++) {
                if (a[j]==a[k]) {
                    m++;
                    for(l=0;l<n;l++) {
                        if (l!=k) {
                            b[a[l]%10]++;
                        }
                    }
                    for(l=0;l<10;l++) {
                        if (b[l]==0) {
                            a[k]=a[k]/10*10+l;
                            break;
                        }
                    }
                    memset(b,0,sizeof(b));
                }
            }
        }

        cout<<m<<endl;
        for(j=0;j<n;j++) {
            cout<<a[j]/1000<<a[j]/100%10<<a[j]/10%10<<a[j]%10<<endl;
        }
    }
    return 0;
}