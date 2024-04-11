#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
int n,k;
int inf = 1e9;
bool a[maxn];
vector<int> max_games(int l,int r) {
    if(r-l+1==4) {
        vector<int> b;
        b.resize(9);
        for(int i=0;i<9;i++) b[i]=-inf;
        for(int i=0;i<2;i++) {
            for(int j=0;j<2;j++) {
                int c=0;
                int g=0;
                int d=0;
                if(a[l] || a[l+1]) c++;
                if(a[l+2] || a[l+3]) c++;
                if(a[l+i] || a[l+2+j]) {
                    c++;
                    g++;
                }
                if(a[l+i] && a[l+2+j]) g++;
                if(a[l+1-i] || a[l+3-j]) {
                    c++;
                    d++;
                }
                if(a[l+i] && a[l+2+j]) d++;
                b[3*g+d]=max(b[3*g+d],c);
            }
        }
        return b;
    }
    int m=(l+r)>>1;
    vector<int> bl = max_games(l,m);
    vector<int> br = max_games(m+1,r);
    /*printf("%d %d %d\n\n\n\n\n",l,m,r);
    for(auto t:bl) printf("%d ",t);
    printf("\n");
    for(auto t:br) printf("%d ",t);
    printf("\n");*/
    vector<int> b;
    b.resize(9);
    for(int i=0;i<9;i++) b[i]=-inf;
    vector<int> tl;
    tl.resize(4);
    for(int i=0;i<4;i++) tl[i]=-inf;
    for(int g=0;g<3;g++) {
        for(int d=0;d<3;d++) {
            int c=bl[3*g+d];
            for(int i=0;i<2;i++) {
                for(int j=0;j<2;j++) {
                    for(int k=0;k<2;k++) {
                        int ng=0,nd=0,nc=c;
                        if(g==2) ng=1;
                        if(g==1 && i==0) ng=1;
                        if((d==2) || (d==1 && j==0) || (g==2) || (g==1 && i==1)) nc++;
                        if(k==0 && ((d==2) || (d==1) && j==0)) nd=1;
                        if(k==1 && ((g==2) || (g==1 && i==1))) nd=1;
                        //cout<<ng*2+nd<<" "<<nc<<" "<<c<<" "<<3*g+d<<" "<<bl.size()<<" "<<bl[3*g+d]<<endl;
                        tl[ng*2+nd]=max(tl[ng*2+nd],nc);
                    }
                }
            }
        }
    }
    vector<int> tr;
    tr.resize(4);
    for(int i=0;i<4;i++) tr[i]=-inf;
    for(int g=0;g<3;g++) {
        for(int d=0;d<3;d++) {
            int c=br[3*g+d];
            for(int i=0;i<2;i++) {
                for(int j=0;j<2;j++) {
                    for(int k=0;k<2;k++) {
                        int ng=0,nd=0,nc=c;
                        if(g==2) ng=1;
                        if(g==1 && i==0) ng=1;
                        if((d==2) || (d==1 && j==0) || (g==2) || (g==1 && i==1)) nc++;
                        if(k==0 && ((d==2) || (d==1) && j==0)) nd=1;
                        if(k==1 && ((g==2) || (g==1 && i==1))) nd=1;
                        tr[ng*2+nd]=max(tr[ng*2+nd],nc);
                    }
                }
            }
        }
    }

    /*printf("%d %d %d\n\n\n\n\n",l,m,r);
    for(auto t:tl) printf("%d ",t);
    printf("\n");
    for(auto t:tr) printf("%d ",t);
    printf("\n");*/


    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            for(int g=0;g<2;g++) {
                for(int h=0;h<2;h++) {
                    int c=tl[i*2+j]+tr[g*2+h];
                    if(i || g) c++;
                    if(j || h) c++;
                    b[3*(i+g)+j+h]=max(b[3*(i+g)+j+h],c);
                }
            }
        }
    }

    return b;
}
int main() {
    scanf("%d %d",&n,&k);
    n=(1<<n);
    int x;
    for(int i=0;i<k;i++) {
        scanf("%d",&x);
        a[x]=true;
    }
    vector<int> b=max_games(1,n);
    int ans=0;
    for(int t=0;t<9;t++) {
        int c=b[t];
        if(t%3!=0) c+=2;
        if(t>=3 && t%3==0) c++;
        ans=max(ans,c);
    }
    printf("%d",ans);
    return 0;
}