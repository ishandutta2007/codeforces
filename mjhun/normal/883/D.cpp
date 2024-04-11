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

int n;
char s[1<<20];
int np[1<<20],na[1<<20];
bool f[1<<20];
vector<int> p,a;

bool can(int t){
	f[n]=true;
	for(int i=n-1;i>=0;--i){
		if(s[i]=='.')f[i]=f[i+1];
		else if(s[i]=='P')f[i]=f[min(np[i],i+t+1)];
		else if(np[i]>=n||np[i]-t>i)f[i]=false;
		else {
			f[i]=f[np[i]+1];
			if(!f[i]&&np[np[i]]<=min(i+t,n-1)){
				f[i]=f[min(np[np[np[i]]],np[i]+t+1)];
			}
		}
	}
	return f[0];
}

int main(){
	scanf("%d%s",&n,s);
	fore(i,0,n){
		if(s[i]=='*')a.pb(i);
		if(s[i]=='P')p.pb(i);
	}
	if(SZ(p)==1){
		int k=lower_bound(a.begin(),a.end(),p[0])-a.begin();
		if(k==SZ(a)-k)printf("%d %d\n",k,min(p[0]-a[0],a.back()-p[0]));
		else if(k>SZ(a)-k)printf("%d %d\n",k,p[0]-a[0]);
		else printf("%d %d\n",SZ(a)-k,a.back()-p[0]);
		return 0;
	}
	int naa=n,npp=n;
	for(int i=n-1;i>=0;--i){
		na[i]=naa;
		np[i]=npp;
		if(s[i]=='*')naa=i;
		else if(s[i]=='P')npp=i;
	}
	int s=0,e=n;
	while(e-s>1){
		int m=(s+e)/2;
		if(can(m-1))e=m;
		else s=m;
	}
	printf("%d %d\n",SZ(a),s);
	return 0;
}