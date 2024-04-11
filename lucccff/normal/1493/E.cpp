#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,t;
    char *a, *b;
    cin>>n;
    a=(char *)malloc(n*sizeof(char));
    b=(char *)malloc(n*sizeof(char));
    getchar();
    for(i=0;i<n;i++){
        a[i]=getchar();
    }
    getchar();
    for(i=0;i<n;i++){
        b[i]=getchar();
    }
    j=0;
    while((j<n)&&(a[j]=='0')&&(b[j]=='0')) j++;
    if (j==n){
        cout<<'0';
    }
    else if ((a[j]=='0')&&(b[j]=='1')){
        for(i=j;i<n;i++) cout<<'1';
    }
    else {
        for(i=j;i<n-1;i++) cout<<b[i];
        t=0;
        for(i=j;i<n;i++) if (a[i]!=b[i]){
            t=1;
            break;
        }
        if (t!=0){
            i=n-1;
            while(a[i]=='1') a[i--]='0';
            a[i]='1';
            t=0;
            for(i=j;i<n;i++) if (a[i]!=b[i]){
                t=1;
                break;
            }
        }
        if (t) cout<<'1';
        else cout<<b[n-1];
    }
    return 0;
}