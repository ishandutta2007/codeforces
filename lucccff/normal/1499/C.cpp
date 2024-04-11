#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l1,l2,m1,m2,m,n,t,s1,s2;
    long long a[200000];
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        for(j=0;j<n;j++) cin>>a[j];
        m1=a[0];
        s1=a[0];
        m2=a[1];
        s2=a[1];
        l1=a[0]*n;
        l2=a[1]*n;
        m=a[0]*n+a[1]*n;
        for(j=2;j<n;j++) {
            if (j%2==0) {
                if (m1>a[j]) m1=a[j];
                s1+=a[j];
                l1=s1+(n-j/2-1)*m1;
                if (l1+l2<m) m=l1+l2;
            }
            else {
                if (m2>a[j]) m2=a[j];
                s2+=a[j];
                l2=s2+(n-(j+1)/2)*m2;
                if (l1+l2<m) m=l1+l2;
            }
        }
        cout<<m<<endl;
    }
    return 0;
}