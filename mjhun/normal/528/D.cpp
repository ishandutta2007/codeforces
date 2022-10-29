#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

struct base {
	double r,i;
	base(double r=0, double i=0): r(r), i(i) {}
	double real()const{return r;}
	void operator/=(const int c){r/=c;i/=c;}
};

base operator *(const base& a, const base& b){
	return base(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
base operator +(const base& a, const base& b){
	return base(a.r+b.r,a.i+b.i);}
base operator -(const base& a, const base& b){
	return base(a.r-b.r,a.i-b.i);}
vector<int> rev;
vector<base> wlen_pw;

inline static void fft(base a[], int n, bool invert){
	fore(i,0,n)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int len=2;len<=n;len<<=1){
		double ang=2*M_PI/len*(invert?-1:1);
		int len2=len>>1;
		base wlen(cos(ang),sin(ang));
		wlen_pw[0]=base(1,0);
		fore(i,1,len2)wlen_pw[i]=wlen_pw[i-1]*wlen;
		for(int i=0;i<n;i+=len){
			base t,
				*pu=a+i,
				*pv=a+i+len2,
				*pu_end=a+i+len2,
				*pw=&wlen_pw[0];
			for(;pu!=pu_end;++pu,++pv,++pw){
				t=*pv * *pw;
				*pv=*pu-t;
				*pu=*pu+t;
			}
		}
	}
	if(invert)fore(i,0,n)a[i]/=n;
}

inline static void calc_rev(int n){
	wlen_pw.resize(n);
	rev.resize(n);
	int lg=31-__builtin_clz(n);
	fore(i,0,n){
		rev[i]=0;
		fore(k,0,lg)if(i&(1<<k))
			rev[i]|=1<<(lg-1-k);
	}
}

inline static void multiply(const vector<int>& a, const vector<int>& b, vector<int>& res){
	vector<base> fa(a.begin(),a.end()), fb(b.begin(),b.end());
	int n=1;
	while(n<max(a.size(),b.size()))n<<=1;
	n<<=1;
	calc_rev(n);
	fa.resize(n);fb.resize(n);
	fft(&fa[0],n,false);fft(&fb[0],n,false);
	fore(i,0,n)fa[i]=fa[i]*fb[i];
	fft(&fa[0],n,true);
	res.resize(n);
	fore(i,0,n)res[i]=int(fa[i].real()+0.5);
}

char ls[]={'A','T','G','C'};

int ns,nt,k;

vector<int> S;
vector<int> T;
vector<int> R;

char s[200005];
char t[200005];
vector<int> rs[4];
int sol[200005];
int w[200005];
int ss;

void solve(char c, vector<int>& r){
	memset(w,0,sizeof(w));
	fore(i,0,ns){
		if(s[i]==c){
			w[max(i-k,0)]++;
			w[min(i+k+1,ns)]--;
		}
	}
	S.clear();T.clear();
	int a=0;
	fore(i,0,ns){
		a+=w[i];
		if(a)S.pb(1);
		else S.pb(0);
//		printf("%d",S[i]);
	}
//	puts("");
	int kk=0;
	fore(i,0,nt){
		kk+=t[i]==c;
		T.pb(t[i]==c);
//		printf("%d",T[i]);
	}
//	puts("");
	reverse(T.begin(),T.end());
	multiply(S,T,R);
//	fore(i,0,R.size())printf("%d",R[i]);puts("");
	fore(i,nt-1,ns){
		if(kk==R[i])r.pb(i-nt+1);
	}
/*	printf("r:");
	fore(i,0,r.size()){
		printf(" %d",r[i]);
	}
	puts("");
*/
}

int main(){
	scanf("%d%d%d%s%s",&ns,&nt,&k,s,t);
	fore(i,0,4)solve(ls[i],rs[i]);
	fore(i,0,rs[0].size())sol[ss++]=rs[0][i];
	fore(i,1,4){
		ss=set_intersection(sol,sol+ss,rs[i].begin(),rs[i].end(),sol)-sol;
	}
	printf("%d\n",ss);
	return 0;
}