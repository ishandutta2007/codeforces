#include <bits/stdc++.h>
using namespace std;

map <int,int> l,r;

int main(){
    long long i,j,k,l1,l2,m,n,t,r1,r2,x,y,maxb,maxc,dm,em;
    int a[1000010],b[1000010],c[1000010],d[1000010],e[1000010],mb[1000010],mc[1000010];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(b,0,sizeof(c));
    char ch;
    cin>>n;
    getchar();
    k=0;
    m=0;
    t=0;
    maxb=0;
    maxc=0;
    mb[0]=mc[0]=-1;
    dm=em=0;
    for(i=0;i<n;i++) {
        ch=getchar();
        if (ch=='R') {
            k++;
            b[k]=b[k-1]+a[k];
            if (b[k]>maxb) {
                maxb=b[k];
                mb[maxb]=k;
            }
            if (k>mc[maxc]) {
                maxc--;
            }
            if (b[k]<0) {
                l[k]=1;
            }
            if (r.count(k-1)) {
                r.erase(k-1);
            }
            if (k>m) {
                m=k;
                c[k]=a[k];
            }

        }
        else if (ch=='L') {
            k--;
            if (k<0) k++;
            c[k]=c[k+1]+a[k];
            if (-c[k]>maxc) {
                maxc=-c[k];
                mc[maxc]=k;
            }
            if (k<mb[maxb]) {
                maxb--;
            }
            if (c[k]>0) {
                r[k]=1;
            }
            if (l.count(k+1)) {
                l.erase(k+1);
            }
        }
        else if (ch=='(') {
            t=t-a[k]+1;
            a[k]=1;
            c[k]=c[k+1]+a[k];
            if (k==mc[maxc]) {
                if (-c[k]<maxc) {
                    maxc--;
                }
            }
            if (-c[k]>maxc) {
                maxc=-c[k];
                mc[maxc]=k;
            }
            if (k>0) b[k]=b[k-1]+a[k];
            else b[k]=a[k];
            if (k==mb[maxb]) {
                if (b[k]<maxb) {
                    maxb--;
                }
            }
            if (b[k]>maxb) {
                maxb=b[k];
                mb[maxb]=k;
            }
            if (l.count(k)&&b[k]>=0) {
                l.erase(k);
            }
            if (b[k]<0) {
                l[k]=1;
            }
            if (r.count(k)&&c[k]<=0) {
                r.erase(k);
            }
            if (c[k]>0) {
                r[k]=1;
            }
        }
        else if (ch==')') {
            t=t-a[k]-1;
            a[k]=-1;
            c[k]=c[k+1]+a[k];
            if (k==mc[maxc]) {
                if (-c[k]<maxc) {
                    maxc--;
                }
            }
            if (-c[k]>maxc) {
                maxc=-c[k];
                mc[maxc]=k;
            }
            if (k>0) b[k]=b[k-1]+a[k];
            else b[k]=a[k];
            if (k==mb[maxb]) {
                if (b[k]<maxb) {
                    maxb--;
                }
            }
            if (b[k]>maxb) {
                maxb=b[k];
                mb[maxb]=k;
            }
            if (l.count(k)&&b[k]>=0) {
                l.erase(k);
            }
            if (b[k]<0) {
                l[k]=1;
            }
            if (r.count(k)&&c[k]<=0) {
                r.erase(k);
            }
            if (c[k]>0) {
                r[k]=1;
            }
        }
        else {
            t=t-a[k];
            a[k]=0;
            c[k]=c[k+1]+a[k];
            if (k==mc[maxc]) {
                if (-c[k]<maxc) {
                    maxc--;
                }
            }
            if (-c[k]>maxc) {
                maxc=-c[k];
                mc[maxc]=k;
            }
            if (k>0) b[k]=b[k-1]+a[k];
            else b[k]=a[k];
            if (k==mb[maxb]) {
                if (b[k]<maxb) {
                    maxb--;
                }
            }
            if (b[k]>maxb) {
                maxb=b[k];
                mb[maxb]=k;
            }
            if (l.count(k)&&b[k]>=0) {
                l.erase(k);
            }
            if (b[k]<0) {
                l[k]=1;
            }
            if (r.count(k)&&c[k]<=0) {
                r.erase(k);
            }
            if (c[k]>0) {
                r[k]=1;
            }
        }
        if (t==0&&l.empty()&&r.empty()) {
            if (maxc>maxb) cout<<maxc<<' ';
            else cout<<maxb<<' ';
        }
        else {
            cout<<-1<<' ';
        }
    }
    return 0;
}