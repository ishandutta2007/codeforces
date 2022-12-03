#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,x,y,z;
    int a[10010],b[10010][30],c[10010][30],f[30];
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    cin>>n>>k;
    cout<<"or "<<1<<' '<<2<<endl<<flush;
    cin>>x;
    cout<<"and "<<1<<' '<<2<<endl<<flush;
    cin>>y;
    for(i=0;i<30;i++) {
        b[0][i]=(x&1)+(y&1);
        x>>=1;
        y>>=1;
    }
    cout<<"or "<<2<<' '<<3<<endl<<flush;
    cin>>x;
    cout<<"and "<<2<<' '<<3<<endl<<flush;
    cin>>y;
    for(i=0;i<30;i++) {
        b[1][i]=(x&1)+(y&1);
        x>>=1;
        y>>=1;
    }
    cout<<"or "<<3<<' '<<1<<endl<<flush;
    cin>>x;
    cout<<"and "<<3<<' '<<1<<endl<<flush;
    cin>>y;
    for(i=0;i<30;i++) {
        b[2][i]=(x&1)+(y&1);
        x>>=1;
        y>>=1;
    }
    memset(f,0,sizeof(f));
    for(i=0;i<30;i++) {
        f[i]=b[0][i]+b[1][i]+b[2][i];
        f[i]>>=1;
    }
    for(i=0;i<30;i++) {
        c[1][i]=f[i]-b[1][i];
    }
    for(i=0;i<30;i++) {
        c[2][i]=f[i]-b[2][i];
    }
    for(i=0;i<30;i++) {
        c[3][i]=f[i]-b[0][i];
    }
    for(i=0;i<30;i++) {
        f[i]=c[1][i];
    }
    for(i=4;i<=n;i++) {
        cout<<"or "<<1<<' '<<i<<endl<<flush;
        cin>>x;
        cout<<"and "<<1<<' '<<i<<endl<<flush;
        cin>>y;
        for(j=0;j<30;j++) {
            c[i][j]=(x&1)+(y&1)-f[j];
            x>>=1;
            y>>=1;
        }
    }
    for(i=1;i<=n;i++) {
        x=0;
        for(j=29;j>=0;j--) x=(x<<1)+c[i][j];
        a[i]=x;
    }
    sort(a+1,a+n+1);
    cout<<"finish "<<a[k]<<endl<<flush;
    return 0;
}

/*7 6
1 6 4 2 3 5 4*/