#include <bits/stdc++.h>
using namespace std;

typedef pair <int,int> pi;
map <pi,long long> p;

int main(){
    int i,j,k,l,m,n,s,y;
    int a[100010][3],b[100010][3];
    pi c;
    memset(a,0,sizeof(a));
    cin>>n;
    for(i=0;i<n-2;i++) {
        cin>>b[i][0]>>b[i][1]>>b[i][2];
    }
    /*for(i=0;i<n-2;i++) {
        for(j=0;j<=2;j++) {
            if (!p.count(b[i][j])) {
                p[b[i][j]]=i+1;
            }
            else {
                p[b[i][j]]=p[b[i][j]]*n+i+1;
            }
        }
    }

    l=0;
    for(i=1;i<=n;i++) {
        if (p[i]<n) {
            if (l!=0) {
                k=p[i];
            }
            else {
                l=p[i];
            }
        }

    }*/
    for(i=0;i<n-2;i++) {
        for(j=0;j<=2;j++) {
            c.first=b[i][j];
            c.second=b[i][(j+1)%3];
            if (p.count(c)) {
                k=p[c];
                a[i][++a[i][0]]=k;
                a[k][++a[k][0]]=i;
            }
            p[c]=i;
            c.first=b[i][(j+1)%3];
            c.second=b[i][j];
            p[c]=i;
        }
    }
    for(i=0;i<n-2;i++) {
        if (a[i][0]==1) break;
    }
    l=i;
    j=1;
    for(i=0;i<n-3;i++) {
        k=a[l][j];
        if (i<n-4) if (a[k][1]==l) j=2;
        else j=1;
        for(int q=0;q<=2;q++) {
            s=b[l][q];
            int f=0;
            for(int x=0;x<=2;x++) {
                if (b[k][x]==s) {
                    f=1;
                    break;
                }
            }
            if (f==0) break;
        }
        cout<<s<<' ';
        if (i<n-4) l=k;
    }

    j=3-j;
    k=a[l][j];
    for(int q=0;q<=2;q++) {
        s=b[l][q];
        int f=0;
        for(int x=0;x<=2;x++) {
            if (b[k][x]==s) {
                f=1;
                break;
            }
        }
        if (f==0) break;
    }

    j=3-j;
    l=a[l][j];
    k=a[l][1];
    for(int q=0;q<=2;q++) {
        y=b[l][q];
        int f=0;
        for(int x=0;x<=2;x++) {
            if (b[k][x]==y) {
                f=1;
                break;
            }
        }
        if (f==0) break;
    }


    for(int x=0;x<=2;x++) {
        int f=0;
        if (b[l][x]==y) {
            f=1;
        }
        if (b[l][x]==s) {
            f=1;
        }
        if (f==0) cout<<b[l][x]<<' ';
    }
    
    cout<<s<<' ';
    cout<<y<<' ';
    
    return 0;
}