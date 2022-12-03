#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main(){
    long long i,j,k,l,m,n,t,x;
    int a[1000010];
    char ch;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>x;
        getchar();
        ch=getchar();
        n=0;
        l=0;
        while(ch!='\n'&&ch) {
            a[n++]=(int)(ch-48);
            if (a[n-1]!=1) l=1;
            ch=getchar();
        }
        if (l==0) {
            cout<<n<<endl;
            continue;
        }
        m=n;
        l=0;
        for(j=1;j<=x;j++) {
            if (a[j-1]==2) {
                if (l==0) if (m*2-j>x) {
                    for(k=m;k<=x;k++) {
                        a[k]=a[k-m+j];
                    }
                    l=1;
                }
                else {
                    for(k=m;k<m*2-j;k++) {
                        a[k]=a[k-m+j];
                    }
                }
                m=(MOD+m*2-j)%MOD;
            }
            else if (a[j-1]==3) {
                if (l==0) if (m*3-j*2>x) {
                    for(k=m;k<=x;k++) {
                        a[k]=a[k-m+j];
                    }
                    l=1;
                }
                else {
                    for(k=m;k<m*3-j*2;k++) {
                        a[k]=a[k-m+j];
                    }
                }
                m=(MOD+m*3-j*2)%MOD;
            }
        }
        cout<<m<<endl;
    }
    return 0;
}