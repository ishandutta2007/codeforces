#include<bits/stdc++.h>
using namespace std;


#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
    ost<<"{"<<p.first<<","<<p.second<<"}";
    return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
    ost<<"{";
    for(int i=0;i<v.size();i++){
        if(i)ost<<",";
        ost<<v[i];
    }
    ost<<"}";
    return ost;
}

using Cd = complex<double>;
namespace std {
  template<>
  Cd& Cd::operator*=(const Cd& y) {
    double a = this->real();
    double b = this->imag();
    double c = y.real();
    double d = y.imag();
    return *this=Cd(a*c-b*d, a*d+b*c);
  }
}
 
template<int32_t lg>
struct FastFourierTransform{
    using C=complex<double>;
    using Array=array<C,1<<lg>;

    static constexpr double PI=acos(-1);
 
    static void dft(Array &f,int n){
		int s=__lg(n);
	
		static vector<vector<C>>w(30);
		w[0].assign(1,1.0);
		for(int i=1;i<=s;i++){
			if(w[i].size())continue;
			w[i].resize(1<<i);
			const double t=2*PI/(1<<i);
			for(int j=0;j<1<<i;j++)w[i][j]=(j&1)?polar(1.0,j*t):w[i-1][j>>1];
		}
 
        for(int i=0,j=1;j<n-1;j++){
            for(int k=n>>1;k>(i^=k);k>>=1);
            if(i>j)swap(f[i],f[j]);
        }
 
		for(int m=1;m<=s;m++){
			for(int i=0;i<n;i+=1<<m){
				for(int j=0;j<1<<m-1;j++){
					C f0=f[i+j],f1=w[m][j]*f[i+j+(1<<m-1)];
					f[i+j]=f0+f1;
					f[i+j+(1<<m-1)]=f0-f1;
				}
			}
		}
	}
	static void idft(Array &f,int n){
		dft(f,n);
		reverse(f.begin()+1,f.begin()+n);
		double in=1.0/n;
		for(int i=0;i<n;i++)f[i]*=in;
	}
 
    static vector<double>convolute(const vector<double>&A,const vector<double>&B){
        int n=1<<__lg(A.size()+B.size()-2)+1;
        static Array g,h;
        for(int i=0;i<n;i++)g[i]=h[i]=0;
        for(int i=0;i<A.size();i++)g[i]=A[i];
        for(int i=0;i<B.size();i++)h[i]=B[i];
 
        dft(g,n);
        dft(h,n);
        for(int i=0;i<n;i++)g[i]*=h[i];
        idft(g,n);
 
        vector<double>AB(A.size()+B.size()-1);
        for(int i=0;i<AB.size();i++)AB[i]=g[i].real();
        return AB;
    }
};
using FFT=FastFourierTransform<18>;

using D=double;

int N,M,T,X;
int A[111],B[111],C[111];
D P[111][22222];
D acc[111][22222];
const int INF=1001001001;
int dist[55][55];


D sum[111][22222];
D dp[111][22222];

void solve(int l,int r){
    if(l+1==r){
        for(int i=0;i<N;i++)dp[i][l]=1e20;
        dp[N-1][l]=0;
        for(int i=0;i<M;i++){
            D tmp=C[i]+sum[i][l]+acc[i][T-l+1]*(X+dist[B[i]][N-1]);
            chmin(dp[A[i]][l],tmp);
        }
        return;
    }

    int m=(l+r)>>1;
    int len=r-l;
    solve(m,r);
    for(int i=0;i<M;i++){
        vector<double>x(r-m),y(len),z;
        for(int j=m;j<r;j++)x[j-m]=dp[B[i]][j];
        for(int j=1;j<len;j++)y[len-j]=P[i][j];
        z=FFT::convolute(x,y);
        for(int j=l;j<m;j++){
            sum[i][j]+=z[j-m+len];
        }
    }
    solve(l,m);
}

signed main(){
    scanf("%d%d%d%d",&N,&M,&T,&X);
    fill_n(*dist,55*55,INF);
    rep(i,N)dist[i][i]=0;
    rep(i,M){
        scanf("%d%d%d",&A[i],&B[i],&C[i]),A[i]--,B[i]--;
        dist[A[i]][B[i]]=C[i];
        for(int j=1;j<=T;j++){
            int p;scanf("%d",&p);
            acc[i][j]=P[i][j]=1.0*p/100000;
        }
        for(int j=T;j>0;j--)acc[i][j-1]+=acc[i][j];
    }
    rep(k,N)rep(i,N)rep(j,N)chmin(dist[i][j],dist[i][k]+dist[k][j]);

    solve(0,T+1);
    printf("%.20f\n",dp[0][0]);
    return 0;
}