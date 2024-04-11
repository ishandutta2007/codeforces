#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[1000010];

map <int,int> p; 

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t,r,x,y;
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    m=0;
    for(i=19;i>=0;i--) {
        x=0;
        y=0;
        for(j=0;j<n;j++) {
            if (((a[j])>>i)&1) {
                x++;
                y^=(a[j]>>i);
                if (p.count(y)) {
                    m=max(m,x-p[y]);
                }
                else {
                    p[y]=x;
                }
            }
            else {
                x=0;
                y=0;
                p.clear();
                p[0]=0;
            }
        }
    }
    cout<<m;
    return 0;
}