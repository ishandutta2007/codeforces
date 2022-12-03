#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
    long long i,j,k,l,m,n,t,r1,r2;
    long long a[300010],b[300010];
    char c[100010],d[100010],ch;
    cin>>t;
    getchar();
    for(i=0;i<t;i++) {
        n=m=0;
        ch=getchar();
        while(ch!='\n'&&ch&&ch!=EOF) {
            c[n++]=ch;
            ch=getchar();
        }
        ch=getchar();
        while(ch!='\n'&&ch&&ch!=EOF) {
            d[m++]=ch;
            ch=getchar();
        }
        if (m>n) {
            cout<<"NO\n";
            continue;
        }
        r1=n-1;
        r2=m-1;
        while(r1>=0&&r2>=0) {
            if (c[r1]!=d[r2]) r1-=2;
            else {
                r1--;
                r2--;
            }
        }
        if (r2>=0) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}