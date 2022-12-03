#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    long long i,j,k,l,m,n,t;
    long long a[1010],b[1010],c[1010],d[1010][1010],e[1010],ans[1010],f[1010],s[1010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=1;j<=n;j++) {
            cin>>a[j];
            e[j]=0;
            f[j]=1;
        }
        a[0]=0;
        for(j=1;j<=n;j++) {
            if (a[j]==1) {
                b[j]=j-1;
                c[j]=1;
                d[1][e[1]++]=j;
            }
            else {
                e[a[j]-1]--;
                b[j]=d[a[j]-1][e[a[j]-1]];
                f[b[j]]=0;
                c[j]=2;
                d[a[j]][e[a[j]]++]=j;
                for(k=j-1;k>b[j];k--) {
                    if (f[k]==1) {
                        e[a[k]]--;
                        if (d[a[k]][e[a[k]]]!=k)  d[a[k]][e[a[k]]-1]=d[a[k]][e[a[k]]];
                        f[k]=0;
                    }
                }
            }
        }
        for(j=1;j<=n;j++) {
            l=1;
            k=j;
            ans[0]=a[j];
            while(k!=0) {
                if (c[k]==2) k=b[k];
                else {
                    k=b[k];
                    if (k!=0) ans[l++]=a[k];
                }
            }
            for(k=l-1;k>0;k--) {
                cout<<ans[k]<<'.';
            }
            cout<<ans[0]<<endl;
        }
    }
    return 0;
}