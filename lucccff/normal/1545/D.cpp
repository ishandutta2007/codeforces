#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,x,y,z;
    long long a[1010][1010],b[1010],c[1000010],d[1010],e[1010];
    cin>>m>>k;
    memset(c,0,sizeof(c));
    cout<<flush<<endl;
    for(i=0;i<k;i++) {
        b[i]=0;
        d[i]=0;
        for(j=0;j<m;j++) {
            cin>>a[i][j];
            b[i]+=a[i][j];
            d[i]+=a[i][j]*a[i][j];
        }
        sort(a[i],a[i]+m);
        cout<<flush;
    }
    for(i=0;i<k-1;i++) {
        e[i]=b[i+1]-b[i];
    }
    for(i=0;i<k-1;i++) {
        if (e[i]!=e[i+1]) {
            if (i!=0) t=i+2;
            else {
                if (e[2]==e[3]) {
                    t=1;
                }
                else {
                    t=2;
                }
            }
            break;
        }
    }
    if (t>=3) {
        x=d[0]-2*d[1]+d[2];
        z=e[t-1]-e[0];
    }
    else {
        x=d[k-1]-2*d[k-2]+d[k-3];
        z=e[t-1]-e[k-2];
    }
    y=d[t+1]-2*d[t]+d[t-1];
    cout<<t<<' '<<-((y-x)/(z*2)+z)/2<<flush;
    return 0;
}