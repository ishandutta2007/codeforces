#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t,s;
    int a[10000],p[1000],b[200000],c[10000001];
    for(i=0;i<10000;i++) a[i]=0;
    a[0]=a[1]=1;
    l=0;
    k=2;
    while (k<10000) {
        for(i=k*2;i<10000;i+=k) a[i]=1;
        p[l++]=k;
        k++;
        while ((k<10000)&&(a[k]==1)) k++;
    }
    for(i=0;i<=10000000;i++)c[i]=0;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n>>k;
        s=0;
        m=0;
        for(j=0;j<n;j++) {
            cin>>b[j];
            for(k=0;k<l;k++) {
                while(b[j]%(p[k]*p[k])==0)b[j]/=p[k]*p[k];
            }
            if (c[b[j]]++!=0) {
                s++;
                for(k=m;k<j;k++) c[b[k]]--;
                m=j;
            }
        }
        for(k=m;k<n;k++) c[b[k]]--;
        cout<<s+1<<endl;
    }
    return 0;
}