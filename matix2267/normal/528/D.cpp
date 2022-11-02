#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int MAXN = 1000006;

const double PI=atan(1)*4;
typedef vector<complex<double> > VC;

int deg,log_deg;
VC C;

int rev(int a)
{
	int wyn=0;
	fru(i,log_deg)
	{
		wyn*=2;
		wyn+=a%2;
		a/=2;
	}
	return wyn;
}

void DFT(int strona, VC &A) 
{
	VC AD(deg);
	fru(k,deg)
		AD[rev(k)]=A[k];
	int m=1;
	for(int s=1;s<=log_deg;s++)
	{
		m*=2;
		complex<double> l=1.0,t,u; //jesli strona -1 to mamy odwrotne fft i wn-> wn^-1
		fru(j,m/2)
		{
			for(int k=j;k<deg;k+=m)
			{
				t=l*AD[k+m/2];
				u=AD[k];
				AD[k]=u+t;
				AD[k+m/2]=u-t;
			}
			l=polar(1.0, 2*PI*(j+1)/(double)(strona*m));
		}
	}
	swap(A,AD);
}

vector<int> FFT(VC A, VC B)
{
	int n=max(A.size(),B.size());
	log_deg=1;
	while((1<<log_deg)<n)log_deg++;
	log_deg++;
	deg=1<<log_deg;
	A.resize(deg,0);B.resize(deg,0);
	DFT(1,A);
	DFT(1,B);
	C.resize(deg);
	fru(i,deg) C[i]=A[i]*B[i];
	DFT(-1,C);
	fru(i,deg)C[i]/=deg;
	vector<int> X(deg);
	fru(i,deg)X[i]=round(real(C[i]));
	return X;
}

#define C CCCC

char S[MAXN], T[MAXN];
pii near[MAXN][4];
char ok[MAXN][4];
const char C[5]="ACGT";

void solve() {
	int n,m,k;
	scanf("%d%d%d%s%s",&n,&m,&k,S,T);
	assert(n == strlen(S));
	assert(m == strlen(T));
	fru(h,4) near[0][h].x = S[0]==C[h] ? 0 : -inft;
	fru(i,n) if(i) fru(h,4) near[i][h].x = S[i]==C[h] ? i : near[i-1][h].x;
	fru(h,4) near[n][h].y = inft;
	for(int i=n-1;i>=0;i--) fru(h,4) near[i][h].y = S[i]==C[h] ? i : near[i+1][h].y;
	fru(i,n) fru(h,4) ok[i][h] = near[i][h].x >= i-k || near[i][h].y <= i+k;
	int occ[4] = {0};
	fru(h,4) fru(j,m) occ[h] += T[j]==C[h];
//	fru(h,4) printf("%d ", occ[h]); puts("<-- occ");
	vi uu[4];
	fru(h,4) {
		VC A(n), B(m);
		fru(i,n) A[i] = ok[i][h];
		fru(j,m) B[j] = T[j]==C[h];
		reverse(ALL(B));
		uu[h] = FFT(A,B);
//		tr(it, uu[h]) printf("%d ",*it); puts("");
	}
	int ans = 0;
	fru(i,n) {
		int ix = i+m-1;
//		fru(h,4) printf("%d ",uu[h][ix]); puts("");
		int okk = 0;
		fru(h,4) okk += uu[h][ix]==occ[h];
		ans += okk==4;
	}
	printf("%d\n", ans);
}

int main() {
	//	freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	int t=1;
	//	scanf("%d",&t);
	fru(i,t) solve();
	return 0;
}