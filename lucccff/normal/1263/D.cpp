#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t;
    string s;
    int a[128],b[128][128],c[128],d[128];
    cin>>n;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(d,0,sizeof(d));
    t=0;
    getchar();
    for(i=0;i<n;i++) {
        getline(cin,s);
        memset(a,0,sizeof(a));
        l=s.length();
        for(j=0;j<l;j++) {
            a[s[j]]=1;
        }
        m=0;
        for(j=0;j<128;j++) {
            if (a[j]!=0) {
                c[m++]=j;
            }
        }
        for(j=0;j<m;j++) {
            for(k=0;k<m;k++) {
                b[c[j]][c[k]]=1;
            }
        }
    }
    
    m=0;
    for(k=0;k<128;k++) {
        for(i=0;i<128;i++) {
            for(j=0;j<128;j++) {
                if (b[i][k]&&b[k][j]) b[i][j]=1;
            }
        }
    }
    for(i=0;i<128;i++) {
        if (b[i][i]==1&&d[i]==0) {
            t++;
            for(j=0;j<128;j++) {
                if (b[i][j]==1) {
                    d[j]=t;
                }
            }
        }
    }
    cout<<t;
    return 0;
}