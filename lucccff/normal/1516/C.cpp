#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t,f,s;
    int a[100],b[200010];
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    memset(b,0,sizeof(b));
    b[0]=1;
    for(i=0;i<n;i++) {
        for(j=2000*i+2000-a[i];j>=0;j--) {
            if (b[j]==1) b[j+a[i]]=1;
        }
    }
    s=0;
    for(i=0;i<n;i++) s+=a[i];
    k=s/2;
    f=0;
    if (k*2!=s) f=1;
    if (b[k]==0) f=1;
    if (f==1) {
        cout<<0;
    }
    else {
        cout<<1<<endl;
        k=2;
        f=0;
        while(f==0) {
            for(i=0;i<n;i++) {
                if (a[i]%k!=0) {
                    f=1;
                    break;
                }
            }
            k=k<<1;
        }
        cout<<i+1;
    }
    return 0;
}