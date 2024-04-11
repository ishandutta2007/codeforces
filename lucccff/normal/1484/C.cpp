#include <bits/stdc++.h>
using namespace std;

struct node {
    int *a;
    int n;
};

int main(){
    int i,j,k,l,m,n,t,p,q,r,s;
    int b[100000],c[100000];
    cin>>t;
    for(i=0;i<t;i++){
        struct node *a;
        cin>>n>>m;
        a=(node *)malloc(n*sizeof(node));
        for(j=0;j<n;j++) {
            a[j].n=0;
            a[j].a=(int *)malloc(sizeof(int));
        }
        for(j=0;j<m;j++) {
            cin>>l;
            b[j]=l;
            for(k=0;k<l;k++) {
                cin>>p;
                a[p-1].a=(int *)realloc(a[p-1].a,(a[p-1].n+1)*sizeof(int));
                a[p-1].a[a[p-1].n++]=j;
            }
            c[j]=p-1;
        }
        s=0;
        for(j=0;j<n;j++) {
            if (a[j].n>(int)((m+1)/2)) {
                r=0;
                for(k=0;k<a[j].n;k++) {
                    if (b[a[j].a[k]]==1) r++;
                }
                if (r>(int)((m+1)/2)) s=-1;
                else s=1;
                break;
            }
        }
        if (s==0) {
            cout<<"YES"<<endl;
            for(j=0;j<m;j++) cout<<c[j]+1<<' ';
            cout<<endl;
        }
        else if (s==-1) {
            cout<<"NO"<<endl;
        }
        else {
            q=j;
            for(j=0;j<n;j++) {
                if (j!=q) {
                    for(k=0;k<a[j].n;k++) {
                        c[a[j].a[k]]=j;
                    }
                }
            }
            if (r<(int)((m+1)/2)) for(j=0;j<a[q].n;j++) {
                if (b[a[q].a[j]]!=1) {
                    r++;
                    c[a[q].a[j]]=q;
                    if (r==(int)((m+1)/2)) break;
                }
            }
            cout<<"YES"<<endl;
            for(j=0;j<m;j++) cout<<c[j]+1<<' ';
            cout<<endl;
        }
    }
    return 0;
}