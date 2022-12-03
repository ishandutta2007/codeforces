#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n;
    int a[100010],b[1000010],c[100010];
    map <int,int> p;
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    memset(b,0,sizeof(b));
    k=0;
    m=0;
    l=0;
    j=0;
    c[0]=0;
    int f=0;
    for(i=0;i<n;i++) {
        if (a[i]<0) {
            b[-a[i]]--;
            if (b[-a[i]]<0) {
                f=1;
                break;
            }
            k--;
            if (k==0) {
                m++;
                c[m]=i+1-j;
                j=i+1;
                p.clear();
            }
        }
        else {
            b[a[i]]++;
            if (p.count(a[i])!=0) {
                f=1;
                break;
            }
            p[a[i]]=1;
            k++;
        }
    }
    if (f!=0) {
        cout<<-1;
    }
    else if (k!=0) {
        cout<<-1;
    }
    else {
        cout<<m<<endl;
        for(i=1;i<=m;i++) {
            cout<<c[i]<<' ';
        }
    }
    return 0;
}