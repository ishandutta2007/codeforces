#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

#define MAXN (1<<18)

struct CD {  // or typedef complex<double> CD; (but 4x slower)
	double r,i;
	CD(double r=0, double i=0):r(r),i(i){}
	double real()const{return r;}
	void operator/=(const int c){r/=c, i/=c;}
};
CD operator*(const CD& a, const CD& b){
	return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
CD operator+(const CD& a, const CD& b){return CD(a.r+b.r,a.i+b.i);}
CD operator-(const CD& a, const CD& b){return CD(a.r-b.r,a.i-b.i);}
const double pi=acos(-1.0);
CD cp1[MAXN+9],cp2[MAXN+9];  // MAXN must be power of 2 !!
int R[MAXN+9];
void dft(CD* a, int n, bool inv){
	fore(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		double z=2*pi/m*(inv?-1:1);
		CD wi=CD(cos(z),sin(z));
		for(int j=0;j<n;j+=m){
			CD w=1;
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k];CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
			}
		}
	}
	if(inv)fore(i,0,n)a[i]/=n;
}
void multiply(vector<int>& p1, vector<int>& p2, vector<int>& res){
	int n=p1.size()+p2.size()+1;
	int m=1,cnt=0;
	while(m<=n)m+=m,cnt++;
	fore(i,0,m){R[i]=0;fore(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	fore(i,0,m)cp1[i]=0,cp2[i]=0;
	fore(i,0,p1.size())cp1[i]=p1[i];
	fore(i,0,p2.size())cp2[i]=p2[i];
	dft(cp1,m,false);dft(cp2,m,false);
	fore(i,0,m)cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	n-=2;
	fore(i,0,n)res[i]=(ll)floor(cp1[i].real()+0.5);
}

char s[MAXN],t[MAXN];int n,m;
vector<int> p0,p1,r;
bool w[6][6][MAXN];
int uf[6];
int find(int x){
	if(uf[x]<0)return x;
	return uf[x]=find(uf[x]);
}

int doit(int k){
	fore(i,0,6)uf[i]=-1;
	int nc=6;
	fore(i,0,6)fore(j,i+1,6)if(w[i][j][k]||w[j][i][k]){
		int a=find(i),b=find(j);
		if(a!=b)uf[a]=b,nc--;
	}
	return 6-nc;
}

int main(){
	scanf("%s%s",s,t);n=strlen(s);m=strlen(t);
	//puts(s);
	//printf("%d %d %d\n",n,m,n-m+1);
	fore(i,0,n)s[i]-='a';
	fore(i,0,m)t[i]-='a';
	p0.resize(n);p1.resize(m);r.resize(n+m+5);
	fore(a,0,6)fore(b,0,6){
		if(a==b)continue;
		fore(i,0,n)p0[i]=s[i]==a;
		fore(i,0,m)p1[i]=t[m-1-i]==b;
		multiply(p0,p1,r);
		fore(i,0,n-m+1)w[a][b][i]=(bool)r[m-1+i];
	}
	//printf("%d\n",n-m+1);
	fore(i,0,n-m+1)printf("%d%c",doit(i)," \n"[i==n-m]);
	return 0;
}