#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,x,y,x1,x2,y1,y2;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>m>>x>>y;
        l=abs(x-1)+abs(y-1)+abs(x-n)+abs(y-1)+n-1;
        x1=1;y1=1;x2=n;y2=1;
        if (l<abs(x-1)+abs(y-1)+abs(x-n)+abs(y-m)+n+m-2) {
            l=abs(x-1)+abs(y-1)+abs(x-n)+abs(y-m)+n+m-2;
            x1=1;y1=1;x2=n;y2=m;
        }
        if (l<abs(x-1)+abs(y-1)+abs(x-1)+abs(y-m)+m-1) {
            l=abs(x-1)+abs(y-1)+abs(x-1)+abs(y-m)+m-1;
            x1=1;y1=1;x2=1;y2=m;
        }
        if (l<abs(x-n)+abs(y-1)+abs(x-n)+abs(y-m)+m-1) {
            l=abs(x-n)+abs(y-1)+abs(x-n)+abs(y-m)+m-1;
            x1=n;y1=1;x2=n;y2=m;
        }
        if (l<abs(x-n)+abs(y-1)+abs(x-1)+abs(y-m)+n+m-2) {
            l=abs(x-n)+abs(y-1)+abs(x-1)+abs(y-m)+n+m-2;
            x1=n;y1=1;x2=1;y2=m;
        }
        if (l<abs(x-n)+abs(y-m)+abs(x-1)+abs(y-m)+n-1) {
            l=abs(x-n)+abs(y-m)+abs(x-1)+abs(y-m)+n-1;
            x1=n;y1=m;x2=1;y2=m;
        }
        cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
    }
    return 0;
}