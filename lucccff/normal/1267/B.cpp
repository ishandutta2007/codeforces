#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,x;
    int a[300010];
    char c;
    c=getchar();
    n=0;
    while(c&&c!=EOF&&c!='\n') {
        a[n++]=c;
        c=getchar();
    }
    j=0;
    k=n-1;
    while(j<k) {
        if (a[j]!=a[k]) {
            cout<<0;
            return 0;
        }
        i=j;
        while(a[j]==a[i]&&j<n) j++;
        if (j>k) {
            cout<<j-i+1;
            return 0;
        }
        l=k;
        while(a[k]==a[l]&&k>=0) k--;
        if (j-i+l-k<3) {
            cout<<0;
            return 0;
        }
    }
    cout<<0;
    return 0;
}