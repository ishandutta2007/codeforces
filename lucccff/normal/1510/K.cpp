#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    int a[2010],b[2010];
    cin>>n;
    for(i=1;i<=2*n;i++){
        cin>>a[i];
    }
    if (n%2==0) {
        l=0;
        for(i=1;i<=2*n;i++){
            if (a[i]!=i) {
                l=1;
                break;
            }
        }
        if (l==0) {
            cout<<0;
            return 0;
        }
        l=0;
        for(i=1;i<=n;i++){
            if (a[2*i]!=2*i-1) {
                l=1;
                break;
            }
            if (a[2*i-1]!=2*i) {
                l=1;
                break;
            }
        }
        if (l==0) {
            cout<<1;
            return 0;
        }
        l=0;
        for(i=1;i<=n;i++){
            if (a[n+i]!=i) {
                l=1;
                break;
            }
            if (a[i]!=n+i) {
                l=1;
                break;
            }
        }
        if (l==0) {
            cout<<1;
            return 0;
        }
        l=0;
        for(i=1;i<=n/2;i++){
            if (a[n+2*i]!=2*i-1) {
                l=1;
                break;
            }
            if (a[n+2*i-1]!=2*i) {
                l=1;
                break;
            }
            if (a[2*i]!=n+2*i-1) {
                l=1;
                break;
            }
            if (a[2*i-1]!=n+2*i) {
                l=1;
                break;
            }
        }
        if (l==0) {
            cout<<2;
            return 0;
        }
        cout<<-1;
    }
    else {
        for(i=1;i<=2*n;i++) if (a[i]==1) break;
        l=i;
        b[1]=1;
        for(i=1;i<=n-1;i++) {
            b[2*i]=b[2*i-1]+1;
            b[2*i+1]=(b[2*i]+n-1)%(n*2)+1;
        }
        b[2*n]=n+1;
        k=0;
        for(i=1;i<=n;i++) if (b[i]==l) {
            k=1;
            break;
        }
        m=i;
        if (k==1) {
            for(;i>1;i--) {
                if (i%2==0) {
                    for(j=1;j<=n;j++) {
                        a[2*j-1]+=a[2*j];
                        a[2*j]=a[2*j-1]-a[2*j];
                        a[2*j-1]-=a[2*j];
                    }
                }
                else {
                    for(j=1;j<=n;j++) {
                        a[j+n]+=a[j];
                        a[j]=a[j+n]-a[j];
                        a[j+n]-=a[j];
                    }
                }
            }
            for(i=1;i<=2*n;i++) {
                if (a[i]!=i) {
                    cout<<-1;
                    return 0;
                }
            }
            cout<<m-1;
            return 0;
        }
        k=0;
        for(i=n+1;i<=2*n;i++) if (b[i]==l) {
            k=1;
            break;
        }
        m=i;
        if (k==1) {
            for(;i<=2*n;i++) {
                if (i%2!=0) {
                    for(j=1;j<=n;j++) {
                        a[2*j-1]+=a[2*j];
                        a[2*j]=a[2*j-1]-a[2*j];
                        a[2*j-1]-=a[2*j];
                    }
                }
                else {
                    for(j=1;j<=n;j++) {
                        a[j+n]+=a[j];
                        a[j]=a[j+n]-a[j];
                        a[j+n]-=a[j];
                    }
                }
            }
            for(i=1;i<=2*n;i++) {
                if (a[i]!=i) {
                    cout<<-1;
                    return 0;
                }
            }
            cout<<2*n-m+1;
            return 0;
        }
    }
    return 0;
}