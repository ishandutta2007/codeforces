#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t,s;
    int b[100000];
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n>>m;
        for(j=0;j<m;j++) b[j]=0;
        for(j=0;j<n;j++) {
            cin>>k;
            b[k%m]++;
        }

        s=0;
        if (m%2==0) {
            if (b[0]!=0) s++;
            if (b[m/2]!=0) s++;
            for(j=1;j<m/2;j++) {
                if (b[j]+b[m-j]==0) continue;
                l=b[j]-b[m-j];
                if (l<0) l=-l;
                if (l<1) s++;
                else s+=l;
            }
        }
        else {
            if (b[0]!=0) s++;
            for(j=1;j*2<m;j++) {
                if (b[j]+b[m-j]==0) continue;
                l=b[j]-b[m-j];
                if (l<0) l=-l;
                if (l<1) s++;
                else s+=l;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}