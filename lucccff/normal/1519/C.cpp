#include <bits/stdc++.h>
using namespace std;

bool compare1(int a,int b){
    return a>b;
}

int main(){
    long long a[1000010],b[1000010],c[1000010],w[1000010],ans[1000010];
    long long i,j,k,l,m,n,t,s;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<n;j++) {
            cin>>a[j];
            b[j]=0;
        }
        b[n]=0;
        for(j=0;j<n;j++) {
            b[a[j]]++;
            cin>>w[j];
        }

        m=0;
        for(j=1;j<=n;j++) {
            if (b[j]>m) m=b[j];
        }
        for(j=2;j<=n;j++) {
            b[j]+=b[j-1];
        }
        for(j=0;j<n;j++) {
            c[b[a[j]-1]++]=w[j];
        }
        if(b[0]>1) sort(c,c+b[0],compare1);
        for(j=1;j<n;j++) {
            if(b[j]-b[j-1]>0) sort(c+b[j-1],c+b[j],compare1);
        }
        for(j=1;j<b[0];j++) c[j]+=c[j-1];
        for(j=1;j<n;j++) {
            for(k=b[j-1]+1;k<b[j];k++) c[k]+=c[k-1];
        }
        for(j=0;j<=n;j++) {
            ans[j]=0;
        }
        for(k=0;k<b[0];k++) {
            s=b[0]/(k+1)*(k+1);
            //s=b[0]-b[0]%(k+1);
            ans[k]+=c[s-1];
        }
        for(j=1;j<n;j++) {
            for(k=0;k<b[j]-b[j-1];k++){
                s=(b[j]-b[j-1])/(k+1)*(k+1);
                //s=(b[j]-b[j-1])-(b[j]-b[j-1])%(k+1);
                ans[k]+=c[b[j-1]+s-1];
            }
        }
        for(j=0;j<n;j++) cout<<ans[j]<<' ';
        cout<<endl;
    }
    return 0;
}