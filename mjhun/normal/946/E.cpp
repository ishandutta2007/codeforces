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
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

char s[200005];int n;
char r[200005];
set<ll> v;

bool go(int k, int l, int m){
	//printf(" %d %d %d\n",k,l,m);
	if(k==n)return l&&!m;
	ll a=((1LL*k)<<30)|(m<<1)|l;
	if(v.count(a))return false;
	v.insert(a);
	if(l){
		for(int i=9;i>=0;--i)if(go(k+1,l,m^(1<<i))){
			r[k]='0'+i;
			return true;
		}
	}
	else {
		if(go(k+1,l,m^(1<<(s[k]-'0')))){
			r[k]=s[k];
			return true;
		}
		for(int i=s[k]-'0'-1;i>=0;--i){
			if(!i&&k==0){
				r[k]=r[k+1]=0;
				assert(go(k+2,true,m));
				return true;
			}
			else {
				if(go(k+1,true,m^(1<<i))){
					r[k]='0'+i;
					return true;
				}
			}
		}
	}
	//v.insert(a);
	return false;
}

//#include <sys/resource.h>


int main(){
	//rlimit rl;
	//getrlimit(RLIMIT_STACK, &rl);
	//rl.rlim_cur=1024L*1024L*256L;//256mb
	//setrlimit(RLIMIT_STACK, &rl);
	int tn;
	scanf("%d",&tn);
	while(tn--){
		scanf("%s",s);n=strlen(s);
		v.clear();assert(go(0,0,0));
		int k=0;
		while(!r[k])k++;
		r[n]=0;
		puts(r+k);
	}
	return 0;
}