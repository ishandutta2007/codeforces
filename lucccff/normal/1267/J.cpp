#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t,f,s;
    int a[2000010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<=n;j++) a[j]=0;
        for(j=0;j<n;j++) {
            cin>>k;
            a[k]++;
        }
        m=0;
        k=n;
        for(j=1;j<=n;j++) if (a[j]!=0) {
            a[m++]=a[j];
            if (a[j]<k) k=a[j];
        }
        for(k=k+1;k>0;k--) {
            f=1;
            for(j=0;j<m;j++) {
                if (k*k>a[j]&&(a[j]%k!=0)&&((a[j]/k)+1)*(k-1)>a[j]) {
                    f=0;
                    break;
                }
            }
            if (f) break;
        }
        s=0;
        for(j=0;j<m;j++) {
            l=0;
            while((a[j]-l)%k!=0) {
                s++;
                l+=k-1;
            }
            s+=(a[j]-l)/k;
        }
        cout<<s<<endl;
    }
    return 0;
}