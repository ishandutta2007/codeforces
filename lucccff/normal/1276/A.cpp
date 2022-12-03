#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t;
    int a[150010],ans[150010];
    char ch;
    cin>>t;
    getchar();
    for(i=0;i<t;i++) {
        ch=getchar();
        j=0;
        while(ch!='\n'&&ch) {
            if (ch=='o') {
                a[j]=2;
            }
            else if (ch=='n') {
                a[j]=1;
            }
            else if (ch=='e') {
                a[j]=0;
            }
            else if (ch=='t') {
                a[j]=4;
            }
            else if (ch=='w') {
                a[j]=3;
            }
            else a[j]=-2;
            ch=getchar();
            j++;
        }
        n=j;
        m=0;
        j=0;
        while(j<n) {
            k=j;
            while(k<n&&a[k]!=-2) k++;
            if (k!=j) {
                l=j;
                while (l<k) {
                    int x=l;
                    while(l+1<n&&a[l]==a[l+1]+1) l++;
                    if (l-x==2&&(a[l]==2||a[l]==0)) {
                        ans[m++]=l;
                    }
                    else if (l-x==3) {
                        ans[m++]=l;
                    }
                    else if (l-x==4) {
                        ans[m++]=l-1;
                    }
                    l++;
                }
                j=k+1;
            }
            else {
                j++;
            }
        }
        cout<<m<<endl;
        for(j=0;j<m;j++) {
            cout<<ans[j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}