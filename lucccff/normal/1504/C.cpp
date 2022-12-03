#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t,an,bn,f,p,x;
    int a[200010],b[200010],c[200010];
    string s;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        cin>>s;
        if (n%2!=0) {
            cout<<"NO\n";
            continue;
        }
        if (s[0]!='1') {
            cout<<"NO\n";
            continue;
        }
        if (s[n-1]!='1') {
            cout<<"NO\n";
            continue;
        }

        m=0;
        for(j=0;j<n;j++) if (s[j]=='1') m++;
        if (m%2!=0) {
            cout<<"NO\n";
            continue;
        }

        memset(c,0,sizeof(c));
        a[0]=b[0]=1;
        a[n-1]=b[n-1]=-1;
        c[0]=c[n-1]=1;
        k=l=1;

        k=0;
        for(j=0;j<n;j++) {
            if (s[j]=='1') {
                k++;
                a[j]=b[j]=1;
            }
            if (k*2==m) break;
        }
        for(j++;j<n;j++) {
            if (s[j]=='1') {
                a[j]=b[j]=-1;
            }
        }

        l=1;
        for(j=0;j<n;j++) {
            if (s[j]=='0') {
                a[j]=l;
                b[j]=-l;
                l=-l;
            }
        }
        

        cout<<"YES\n";
        for(j=0;j<n;j++) {
            if (a[j]==1) cout<<'(';
            else cout<<')';
        }
        cout<<endl;
        for(j=0;j<n;j++) {
            if (b[j]==1) cout<<'(';
            else cout<<')';
        }
        cout<<endl;
    }
    return 0;
}