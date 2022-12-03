#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[100010],b[100010];

void init(int n) {
    for(int i=1;i<=n;i++) {
        a[i]=i;
        b[i]=1;
    }
}

int fi(int x) {
    if (a[x]==x) return x;
    else return a[x]=fi(a[x]);
}

void un(int x,int y) {
    int xx=fi(x),yy=fi(y);
    if (b[xx]<b[yy]) swap(xx,yy);
    a[yy]=xx;
    b[xx]+=b[yy];
}

int p[100010],q[100010];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        init(n);
        for(i=0;i<m;i++) {
            /*cin>>k>>l>>j;
            p[i]=k;
            q[i]=j;
            un(k,j);*/
            cin>>k>>l>>j;
            b[l]=0;
        }
        for(i=1;i<=n;i++) {
            if (b[i]) break;
        }
        k=i;
        for(i=1;i<=n;i++) {
            if (i!=k) {
                cout<<i<<' '<<k<<endl;
            }
        }
        /*for(i=2;i<=n;i++) {
            if (fi(1)!=fi(i)) {
                un(1,i);
                q[m]=1;
                p[m]=i;
                m++;
            }
        }
        for(i=0;i<m;i++) {
            cout<<q[i]<<' '<<p[i]<<endl;
        }*/
    }
    return 0;
}