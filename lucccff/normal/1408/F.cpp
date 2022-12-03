#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,x,y;
    int q=0,a[500010],b[500010];
    cin>>n;
    x=1;
    l=0;
    while(x<n) {
        x<<=1;
        l++;
    }
    x>>=1;
    l--;
    y=1;
    for(i=0;i<l;i++) {
        y<<=1;
        for(j=1;j<=x;j+=y) {
            for(k=0;k<(y>>1);k++) {
                a[q]=j+k;
                b[q]=j+k+(y>>1);
                q++;
            }
        }
    }
    y=1;
    for(i=0;i<l;i++) {
        y<<=1;
        for(j=n-x+1;j<=n;j+=y) {
            for(k=0;k<(y>>1);k++) {
                a[q]=j+k;
                b[q]=j+k+(y>>1);
                q++;
            }
        }
    }
    cout<<q<<endl;
    for(i=0;i<q;i++) {
        cout<<a[i]<<' '<<b[i]<<endl;
    }
    return 0;
}