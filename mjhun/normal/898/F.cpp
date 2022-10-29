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
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

struct Hash {
	int P=10,MOD[2],PI[2];
	vector<int> h[2],pi[2];
	Hash(){}
	Hash(string& s){
		MOD[0]=999727999;MOD[1]=1070777777;
		PI[0]=99972800;PI[1]=749544444;
		fore(k,0,2)h[k].resize(s.size()+1),pi[k].resize(s.size()+1);
		fore(k,0,2){
			h[k][0]=0;pi[k][0]=1;
			ll p=1;
			fore(i,1,s.size()+1){
				h[k][i]=(h[k][i-1]+p*(s[i-1]-'0'))%MOD[k];
				pi[k][i]=(1LL*pi[k][i-1]*PI[k])%MOD[k];
				p=(p*P)%MOD[k];
			}
		}
	}
	pair<int,int> get(int s, int e){
		ll h0=(h[0][e]-h[0][s]+MOD[0])%MOD[0];
		h0=(1LL*h0*pi[0][s])%MOD[0];
		ll h1=(h[1][e]-h[1][s]+MOD[1])%MOD[1];
		h1=(1LL*h1*pi[1][s])%MOD[1];
		return mp(h0,h1);
	}
};

char s[1<<20];int n;
Hash w;

void doit(int la, int lb, int lc){
	assert(la+lb+lc==n);
	if(la<=0||lb<=0||lc<=0)return;
	if(la>1&&s[0]=='0'||lb>1&&s[la]=='0'||lc>1&&s[la+lb]=='0')return;
	auto pa=w.get(n-la,n);
	auto pb=w.get(n-la-lb,n-la);
	auto pc=w.get(0,n-la-lb);
	if((pa.fst+pb.fst)%w.MOD[0]==pc.fst&&(pa.snd+pb.snd)%w.MOD[1]==pc.snd){
		fore(i,0,n){
			if(i==la)putchar('+');
			if(i==la+lb)putchar('=');
			putchar(s[i]);
		}
		puts("");
		exit(0);
	}
}

int main(){
	scanf("%s",s);n=strlen(s);
	string t(s);reverse(t.begin(),t.end());
	w=Hash(t);
	fore(lc,1,n-1){
		doit(lc,n-2*lc,lc);
		doit(lc-1,n-2*lc+1,lc);
		doit(n-2*lc,lc,lc);
		doit(n-2*lc+1,lc-1,lc);
	}
	return 0;
}