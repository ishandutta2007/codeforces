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

vector<int> r[32];
vector<int> s[32];
vector<pair<int,int> > f;
vector<int> d;
vector<int> rr;
int ans;

void gendivs(int k, int c){
	if(k==SZ(f)){
		if(c>1)d.pb(c);
		return;
	}
	fore(_,0,f[k].snd+1){
		gendivs(k+1,c);
		c*=f[k].fst;
	}
}

int main(){
	int tn;
	scanf("%d",&tn);
	while(tn--){
		fore(i,0,32)r[i].clear(),s[i].clear();
		f.clear();d.clear();rr.clear();ans=0;
		int n;
		scanf("%d",&n);
		for(int i=2;i*i<=n;++i)if(n%i==0){
			int q=0;
			while(n%i==0)n/=i,q++;
			f.pb(mp(i,q));
		}
		if(n>1)f.pb(mp(n,1));
		gendivs(0,1);
		if(SZ(f)==1){
			r[0]=d;
		}
		else if(SZ(f)==2){
			if(f[0].snd==1&&f[1].snd==1){
				ans=1;
				r[0]=d;
			}
			else {
				for(int k:d){
					if(k%f[0].fst==0&&k%f[1].fst==0){
						if(SZ(s[0]))s[1].pb(k);
						else s[0].pb(k);
					}
					else if(k%f[0].fst==0)r[0].pb(k);
					else r[1].pb(k);
				}
			}
		}
		else {
			for(int k:d){
				int a=-1,b=-1;
				fore(i,0,SZ(f))if(k%f[i].fst==0){
					if(a<0)a=i;
					else b=i;
				}
				if(a==0&&b==SZ(f)-1)s[b].pb(k);
				else if(b<0||b>a+1)r[a].pb(k);
				else s[a].pb(k);
			}
		}
		fore(i,0,32){
			for(int t:r[i])rr.pb(t);
			for(int t:s[i])rr.pb(t);
		}
		fore(i,0,SZ(rr))printf("%d%c",rr[i]," \n"[i==SZ(rr)-1]);
		printf("%d\n",ans);
	}
	return 0;
}