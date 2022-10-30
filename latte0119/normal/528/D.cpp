#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

namespace FFT{
    typedef complex<double>C;
    const double PI=acos(-1);

    void dft(vector<C>&f,bool rev=false){
        int n=f.size();
        for(int i=0,j=1;j<n-1;j++){
            for(int k=n>>1;k>(i^=k);k/=2);
            if(i>j)swap(f[i],f[j]);
        }
        for(int m=2;m<=n;m*=2){
            C wr=polar(1.0,(rev?-1:1)*2.0*PI/m);
            for(int i=0;i<n;i+=m){
                C w(1,0);
                for(int j=0;j<m/2;j++){
                    C f0=f[i+j],f1=w*f[i+j+m/2];
                    f[i+j]=f0+f1;
                    f[i+j+m/2]=f0-f1;
                    w*=wr;
                }
            }
        }
        if(rev){
            double t=1.0/n;
            for(int i=0;i<n;i++)f[i]*=t;
        }
    }

    vector<int>multiply(vector<int>A,vector<int>B){
        int n=1;
        while(n<=A.size()+B.size())n<<=1;
        vector<C>g(n),h(n);
        for(int i=0;i<A.size();i++)g[i]=A[i];
        for(int i=0;i<B.size();i++)h[i]=B[i];

        dft(g);
        dft(h);
        for(int i=0;i<n;i++)g[i]*=h[i];
        dft(g,true);

        vector<int>C(A.size()+B.size()-1);
        for(int i=0;i<C.size();i++)C[i]=(int)(g[i].real()+0.5);
        return C;
    }
}


vint in(){
    string s;
    cin>>s;
    vint ret(s.size());
    rep(i,s.size())rep(j,4)if("ATCG"[j]==s[i])ret[i]=j;
    return ret;
}

int N,M,K;
vint S,T;
int acc[4][222222];

signed main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>N>>M>>K;
    S=in();T=in();
    rep(i,N){
        int l=max(0ll,i-K);
        int r=min(N,i+K+1);
        acc[S[i]][l]++;acc[S[i]][r]--;
    }
    rep(i,4)rep(j,N)acc[i][j+1]+=acc[i][j];

    vector<vint>m(4,vint(N));
    rep(i,4){
        vint pS(N),pT(M);
        rep(j,N)pS[j]=acc[i][j]!=0;
        rep(j,M)pT[M-1-j]=T[j]==i;
        vint pX=FFT::multiply(pS,pT);
        rep(j,N)m[i][j]=pX[j+M-1];
    }


    int ans=0;
    rep(i,N){
        int sum=0;
        rep(j,4)sum+=m[j][i];
        if(sum==M)ans++;
    }
    cout<<ans<<endl;
    return 0;
}