#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t;
    int a[1010],b[1010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>m;
        getchar();
        l=0;
        b[0]=k=0;
        for(j=0;j<n;j++) {
            if (getchar()=='0') {
                a[j]=0;
            }
            else {
                a[j]=1;
                l=1;
            }
            k+=a[j];
            b[j+1]=k;
        }
        if (l==0) {
            for(j=0;j<n;j++) cout<<0;
            cout<<endl;
        }
        else {
            for(j=0;j<n;j++) {
                while(j<n&&a[j]==1) j++;
                l=j;
                while(l<n&&a[l]==0) l++;
                if (j==0) {
                    if (l>m) {
                        for(k=l-1;k>=l-m;k--) {
                            a[k]=1;
                        }
                    }
                    else {
                        for(k=0;k<l;k++) {
                            a[k]=1;
                        }
                    }
                }
                else if (l==n) {
                    if (l-j>m) {
                        for(k=j;k<j+m;k++) {
                            a[k]=1;
                        }
                    }
                    else {
                        for(k=j;k<l;k++) {
                            a[k]=1;
                        }
                    }
                }
                else if ((l-j)%2==0) {
                    if (l-j>2*m) {
                        for(k=j;k<j+m;k++) {
                            a[k]=1;
                        }
                        for(k=l-m;k<l;k++) {
                            a[k]=1;
                        }
                    }
                    else {
                        for(k=j;k<l;k++) {
                            a[k]=1;
                        }
                    }
                }
                else {
                    if (l-j>2*m) {
                        for(k=j;k<j+m;k++) {
                            a[k]=1;
                        }
                        for(k=l-m;k<l;k++) {
                            a[k]=1;
                        }
                    }
                    else {
                        for(k=j;k<(l+j)/2;k++) {
                            a[k]=1;
                        }
                        for(k++;k<l;k++) {
                            a[k]=1;
                        }
                    }
                }
                j=l-1;
            }
            for(j=0;j<n;j++) {
                cout<<a[j];
            }
            cout<<endl;
        }
    }
    return 0;
}