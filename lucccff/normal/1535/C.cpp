#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t,s;
    int a[200010],p[200010];
    char ch;
    cin>>t;
    getchar();
    for(i=0;i<t;i++) {
        ch=getchar();
        n=0;
        while(ch&&ch!='\n'&&ch!=EOF) {
            if (ch=='1') {
                a[n]=1;
            }
            else if (ch=='0') {
                a[n]=0;
            }
            else {
                a[n]=-1;
            }
            n++;
            ch=getchar();
        }
        for(j=0;j<n;j++) if(a[j]!=-1)break;
        if (j==n) {
            cout<<n*(n+1)/2<<endl;
            continue;
        }
        j=0;
        s=0;
        while(j<n) {
            k=j;
            while(j<n&&a[j]==-1) {
                j++;
            }
            if (j!=n) {
                l=j;
            }
            while(j<n&&((a[j]-a[l]-l+j)%2==0||a[j]==-1)) {
                j++;
            }
            s+=(j-k)*(j-k+1)/2;
            if (j<n) {
                if (a[j-1]==-1) {
                    j--;
                    k=j;
                    while(j>0&&a[j]==-1) j--;
                    s-=(k-j)*(k-j+1)/2;
                    j++;
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;
}