#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[10000010],b[10000010];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t,x,y;
    LL ans=1e15,p;
    cin>>n;
    for(i=1;i<=n;i++) {
        cin>>k;
        if (a[k]) {
            b[k]=i;
        }
        else {
            a[k]=i;
        }
    }
    for(i=1;i<=10000000;i++) {
        for(j=i;j<=10000000;j+=i) {
            if (a[j]) break;
        }
        if (j<=10000000) {
            k=j;
            if (!b[k]) {
                for(j=j+i;j<=10000000;j+=i) {
                    if (a[j]) break;
                }
            }
            if (j<=10000000) {
                l=j;
                p=1ll*k*l/i;
                if (p<ans) {
                    ans=p;
                    x=k;
                    y=j;
                }
            }
        }
    }
    //cout<<a[x]<<' '<<a[y]<<endl;
    if (x==y) {
        //cout<<a[x]<<' '<<b[y];
        x=a[x];
        y=b[y];
    }
    else {
        //cout<<a[x]<<' '<<a[y];
        x=a[x];
        y=a[y];
    }
    if (x>y) swap(x,y);
    cout<<x<<' '<<y<<endl;
    return 0;
}