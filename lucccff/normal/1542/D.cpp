#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main(){
    long long i,j,k,l,m,n,t,ans=0,inv2=998244353/2+1,s;
    long long a[550],b[550],c[550][550];
    pair <int,int> p[550];
    char ch;
    cin>>n;
    m=0;
    for(i=0;i<n;i++) {
        getchar();
        ch=getchar();
        if (ch=='+') {
            cin>>a[i];
            p[m]=make_pair(a[i],i);
            m++;
        }
        else {
            a[i]=-1;
        }
    }

    sort(p,p+m);

    for(i=0;i<n;i++) {
        b[i]=-1;
    }

    for(i=0;i<m;i++) {
        b[p[i].second]=0;
    }
    for(i=0;i<m;i++) {
        k=p[i].second;
        for(j=0;j<n;j++) {
            for(l=0;l<=n;l++) {
                c[j][l]=0;
            }
        }
        if (k!=0) if (b[0]==0) c[0][0]=2;
        else if (b[0]==1) {
            c[0][0]=1;
            c[0][1]=1;
        }
        else {
            c[0][0]=2;
        }
        else c[0][0]=1;
        for(j=1;j<k;j++) {
            if (b[j]==0) {
                for(l=0;l<=j+1;l++) {
                    c[j][l]=c[j-1][l]*2;
                    if (c[j][l]>=MOD) c[j][l]=c[j][l]-MOD;
                }
            }
            else if (b[j]==1) {
                for(l=1;l<=j+1;l++) {
                    c[j][l]=c[j-1][l]+c[j-1][l-1];
                    if (c[j][l]>=MOD) c[j][l]=c[j][l]-MOD;
                }
                c[j][0]=c[j-1][0];
            }
            else {
                for(l=1;l<=j+1;l++) {
                    c[j][l]=c[j-1][l]+c[j-1][l+1];
                    if (c[j][l]>=MOD) c[j][l]=c[j][l]-MOD;
                }
                c[j][0]=2*c[j-1][0]+c[j-1][1];
                if (c[j][0]>=MOD) c[j][0]=c[j][0]-MOD;
                if (c[j][0]>=MOD) c[j][0]=c[j][0]-MOD;
            }
        }
        if (k!=0) for(l=0;l<=k+1;l++) {
            c[k][l]=c[k-1][l];
        }
        for(j=k+1;j<n;j++) {
            if (b[j]==0) {
                for(l=0;l<=j+1;l++) {
                    c[j][l]=c[j-1][l]*2;
                    if (c[j][l]>=MOD) c[j][l]=c[j][l]-MOD;
                }
            }
            else if (b[j]==1) {
                for(l=1;l<=j+1;l++) {
                    c[j][l]=c[j-1][l]+c[j-1][l-1];
                    if (c[j][l]>=MOD) c[j][l]=c[j][l]-MOD;
                }
                c[j][0]=c[j-1][0];
            }
            else {
                for(l=0;l<=j+1;l++) {
                    c[j][l]=c[j-1][l]+c[j-1][l+1];
                    if (c[j][l]>=MOD) c[j][l]=c[j][l]-MOD;
                }
            }
        }
        s=0;
        for(j=0;j<=n;j++) {
            s=(s+c[n-1][j])%MOD;
        }
        b[k]=1;
        ans=(ans+s*a[k])%MOD;
    }
    cout<<ans;
    return 0;
}