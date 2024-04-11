#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
    long long i,j,k,l,m,n,t,s,ans=0;
    long long a[200010][26],b[200010];
    char c[400010],ch;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        getchar();
        for(j=0;j<n;j++) {
            memset(a[j],0,sizeof(a[j]));
            ch=getchar();
            while(ch!='\n'&&ch&&ch!=EOF) {
                a[j][ch-'a']++;
                ch=getchar();
            }
        }
        ans=0;
        for(j=0;j<26;j++) {
            for(k=0;k<n;k++) {
                b[k]=2*a[k][j];
                for(l=0;l<26;l++) {
                    b[k]-=a[k][l];
                }
            }
            sort(b,b+n);
            s=0;
            for(k=n-1;k>=0;k--) {
                s+=b[k];
                if (s<=0) break;
            }
            if (ans<n-k-1) ans=n-k-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}