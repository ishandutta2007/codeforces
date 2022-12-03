#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,q;
    int a[300010],b[51];
    cin>>n>>q;
    memset(b,-1,sizeof(b));
    for(i=1;i<=n;i++){
        cin>>a[i];
        if (b[a[i]]==-1) b[a[i]]=i;
    }
    for(i=0;i<q;i++) {
        cin>>m;
        for(j=1;j<=50;j++) {
            if (b[j]!=-1) {
                if (b[j]<b[m]) b[j]++;
            }
        }
        cout<<b[m]<<' ';
        b[m]=1;
    }
    return 0;
}