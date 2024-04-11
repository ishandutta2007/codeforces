#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,m,n,t;
    long long l;
    int a[100010],b[100010];
    cin>>n>>m;
    l=0;
    for(i=0;i<m;i++) {
        cin>>a[i];
        l+=a[i];
        if (a[i]+i>n) {
            cout<<-1;
            return 0;
        }
    }
    if (l<n) {
        cout<<-1;
        return 0;
    }
    b[m]=n+1;
    for(i=m-1;i>=0;i--) {
        b[i]=max(i+1,b[i+1]-a[i]);
    }
    for(i=0;i<m;i++) {
        cout<<b[i]<<' ';
    }
    return 0;
}