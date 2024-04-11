#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,ans;
    int a[110][110],b[110];
    pair <int,int> c[110];
    cin>>n>>m;
    for(i=0;i<m;i++) {
        for(j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }

    ans=m;
    for(i=0;i<n-1;i++) {
        for(j=0;j<m;j++) {
            b[j]=a[j][i]-a[j][n-1];
        }
        sort(b,b+m);
        k=0;
        for(j=m-1;j>=0;j--) {
            k+=b[j];
            if (k<0) break;
        }
        if (ans>j+1) {
            ans=j+1;
            l=i;
        }
    }
    cout<<ans<<endl;
    for(i=0;i<m;i++) {
        c[i]=make_pair(a[i][l]-a[i][n-1],i);
    }
    sort(c,c+m);
    for(i=0;i<ans;i++) {
        cout<<c[i].second+1<<' ';
    }
    return 0;
}