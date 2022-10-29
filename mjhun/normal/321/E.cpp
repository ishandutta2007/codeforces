    #include <bits/stdc++.h>
    #ifdef DBP
    #define deb(...) fprintf(stderr,__VA_ARGS__)
    #else
    #define deb(...) 0
    #endif
    #define fore(x,a,b) for(int x=a, qwerty=b; x<qwerty; x++)
    #define ALL(a) (a).begin(),(a).end()
    #define SZ(a) ((int)(a).size())
    #define pb push_back
    #define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
    #define fst first
    #define snd second
    #define mset(a,v) memset((a),(v),sizeof(a))
    using namespace std;
    typedef long long ll;
     
    const int MAXN=4005, INF=1e9;
    int k,n,f[MAXN],f2[MAXN], A[MAXN][MAXN], B[MAXN][MAXN];
    void doit(int s, int e, int s0, int e0, int i){
        if(s==e)return;
        int m=(s+e)/2,r=INF,rp;
        fore(j,s0,min(e0,m)){
            int r0=f[j]+A[j+1][m];
            if(r0<r)r=r0,rp=j;
        }
        f2[m]=r;
        doit(s,m,s0,rp+1,i);doit(m+1,e,rp,e0,i);
    }
    int doall(){
        fill(f,f+MAXN,INF);
        f[0]=0;
        fore(i,1,k)doit(1,n+1,0,n,i),memcpy(f,f2,sizeof(f2));
        return f[n];
    }
     
    int nn, kk;
     
    int main(){//FIN;
        scanf("%d%d",&nn,&kk);k=kk+1;n=nn;
        fore(x,1,nn+1)fore(y,1,nn+1){
            int c;
            while((c=getchar())&&(c<'0'||c>'9'));
            B[x][y]=c-'0';
            B[x][y]=y<x?0:B[x][y];
        }
        fore(x,1,nn+1)fore(y,1,nn+1){
            B[x][y]=B[x][y]+B[x][y-1]+B[x-1][y]-B[x-1][y-1];
        }
        fore(x,1,nn+1)fore(y,x,nn+1)
            A[x][y]=B[y][y]-B[y][x-1]-B[x-1][y]+B[x-1][x-1];
        printf("%d\n",doall());
    }