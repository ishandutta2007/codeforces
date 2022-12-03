#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t,x,y,q;
    int a[2020],b[2020],d[2020],g[2020],h[2020];
    vector <int> e[2020];
    cin>>n;
    cout<<"? "<<1<<endl<<flush;
    x=0;y=-1;
    m=0;
    for(i=1;i<=n;i++) {
        cin>>a[i];
        if (a[i]&1) x++;
        else y++;
        if (a[i]==1) {
            m++;
            e[1].push_back(i);
        }
    }
    if (x<=y) {
        for(i=2;i<=n;i++) {
            if (a[i]&1) {
                cout<<"? "<<i<<endl<<flush;
                for(j=1;j<=n;j++) {
                    cin>>b[j];
                    if (b[j]==1&&j!=1) {
                        m++;
                        e[i].push_back(j);
                    }
                }
            }
        }
    }
    else {
        for(i=2;i<=n;i++) {
            if (!(a[i]&1)) {
                cout<<"? "<<i<<endl<<flush;
                for(j=1;j<=n;j++) {
                    cin>>b[j];
                    if (b[j]==1&&j!=1) {
                        m++;
                        e[i].push_back(j);
                    }
                }
            }
        }
    }

    cout<<"!\n";
    for(i=1;i<=n;i++) {
        for(j=0;j<e[i].size();j++) {
            cout<<i<<' '<<e[i][j]<<endl;
        }
    }
    cout<<flush;
    return 0;
}