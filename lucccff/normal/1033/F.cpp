#include <bits/stdc++.h>
using namespace std;

int a[5000],c[1000010],w,b[5000],d[5000];

int main() {
    long long i,j,k,l,m,n,q,t,s,p,ans,x,y;
    char ch;
    cin>>w>>n>>m;
    memset(a,0,sizeof(a));
    memset(c,0,sizeof(c));
    for(i=0;i<n;i++) {
        cin>>k;
        a[k]++;
    }
    t=1<<w;
    for(i=0;i<t;i++) {
        for(j=0;j<t;j++) {
            x=i;
            y=j;
            p=0;
            q=0;
            for(k=0;k<w;k++) {
                p=p*3+x%2+y%2;
                x>>=1;
                y>>=1;
            }
            for(k=0;k<w;k++) {
                q=q*3+p%3;
                p=p/3;
            }
            c[q]+=a[i]*a[j];
        }
    }
    s=1;
    for(i=0;i<w;i++) s*=3;
    for(i=0;i<m;i++) {
        k=1;
        b[0]=0;
        getchar();
        for(j=0;j<w;j++) {
            q=0;
            ch=getchar();
            switch (ch)
                {
                case 'A' :{
                    for(l=0;l<k;l++) {
                        d[q++]=b[l]*3;
                        d[q++]=b[l]*3+1;
                    }
                    break;
                }
                case 'O' :{
                    for(l=0;l<k;l++) {
                        d[q++]=b[l]*3;
                    }
                    break;
                }
                case 'X' :{
                    for(l=0;l<k;l++) {
                        d[q++]=b[l]*3;
                        d[q++]=b[l]*3+2;
                    }
                    break;
                }
                case 'a' :{
                    for(l=0;l<k;l++) {
                        d[q++]=b[l]*3+2;
                    }
                    break;
                }
                case 'o' :{
                    for(l=0;l<k;l++) {
                        d[q++]=b[l]*3+1;
                        d[q++]=b[l]*3+2;
                    }
                    break;
                }
                case 'x' :{
                    for(l=0;l<k;l++) {
                        d[q++]=b[l]*3+1;
                    }
                    break;
                }
            }
            k=q;
            for(l=0;l<q;l++) {
                b[l]=d[l];
            }
        }
        ans=0;
        for(j=0;j<k;j++) ans+=c[b[j]];
        cout<<ans<<endl;
    }
}