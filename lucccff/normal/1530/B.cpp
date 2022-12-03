#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t;
    long long a[50][50];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>k;
        memset(a,0,sizeof(a));
        for(j=0;j<n;j++) {
            a[j][0]=(j+1)&1;
        }
        for(j=0;j<k;j++) {
            a[0][j]=(j+1)&1;
        }
        if (n&1) {
            for(j=0;j<k;j++) {
                a[n-1][j]=(j+1)&1;
            }
        }
        else {
            for(j=1;j<k;j++) {
                a[n-1][j]=(j+1)&1;
            }
        }
        if (k&1) {
            for(j=0;j<n;j++) {
                a[j][k-1]=(j+1)&1;
            }
        }
        else {
            for(j=1;j<n;j++) {
                a[j][k-1]=(j+1)&1;
            }
        }
        if ((!(n&1))&&(!(k&1))) a[n-2][k-1]=0;
        if (!((n&1)&&(k&1))) a[n-1][k-1]=0;
        for(j=0;j<n;j++) {
            for(l=0;l<k;l++) {
                cout<<a[j][l];
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}