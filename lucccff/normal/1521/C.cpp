#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t,f,max,num,k1,k2,k3;
    long long a[10010];
    srand((unsigned)time(NULL));
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        cout<<'?'<<' '<<1<<' '<<1<<' '<<2<<' '<<n-1<<endl;
        cout<<flush;
        cin>>k1;
        cout<<'?'<<' '<<1<<' '<<3<<' '<<1<<' '<<n-1<<endl;
        cout<<flush;
        cin>>k2;
        cout<<'?'<<' '<<1<<' '<<2<<' '<<3<<' '<<n-1<<endl;
        cout<<flush;
        cin>>k3;
        if ((k1==n)||(k2==n)||(k3==n)) {
            max=n;
            if (k1==n) {
                num=2;
            }
            if (k2==n) {
                num=1;
            }
            if (k3==n) {
                num=3;
            }
        }
        else {
            if (k1==k2) {
                max=k1;
                num=1;
            }
            else if (k1==k3) {
                max=k1;
                num=2;
            }
            else {
                max=k2;
                num=3;
            }
        }
        a[num]=max;
        if (max*2>n) {
            for(j=1;j<=n;j++) {
                if (j!=num) {
                    cout<<'?'<<' '<<2<<' '<<j<<' '<<num<<' '<<1<<endl;
                    cout<<flush;
                    cin>>k;
                    if (k<max) {
                        a[j]=k;
                    }
                    else {
                        cout<<'?'<<' '<<1<<' '<<num<<' '<<j<<' '<<n-1<<endl;
                        cout<<flush;
                        cin>>k;
                        max=k;
                        num=j;
                        a[j]=k;
                    }
                }
            }
        }
        else {
            for(j=1;j<=n;j++) {
                if (j!=num) {
                    cout<<'?'<<' '<<1<<' '<<num<<' '<<j<<' '<<n-1<<endl;
                    cout<<flush;
                    cin>>k;
                    if (k>max) {
                        a[j]=k;
                    }
                    else {
                        cout<<'?'<<' '<<2<<' '<<j<<' '<<num<<' '<<1<<endl;
                        cout<<flush;
                        cin>>k;
                        max=k;
                        num=j;
                        a[j]=k;
                    }
                }
            }
        }
        cout<<'!'<<' ';
        for(j=1;j<=n;j++) {
            cout<<a[j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}