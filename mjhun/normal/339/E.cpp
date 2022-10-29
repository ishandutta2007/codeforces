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

int n,a[1024],ai[1024];
int xl[1024],xr[1024];
int o[8],p[8];bool rv[8];
int s[8],e[8];
vector<pair<int,int> > r;

void doit(int i, int j, bool a=false){
	if(a){
		int ss=0;
		fore(k,0,i)ss+=e[p[k]]-s[p[k]];
		int ee=ss;
		fore(k,i,j+1)ee+=e[p[k]]-s[p[k]];
		if(ss+1<ee)r.pb(mp(ss,ee));
	}
	reverse(p+i,p+j+1);
	reverse(rv+i,rv+j+1);
	fore(k,i,j+1)rv[k]^=1;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i),a[i]--,ai[a[i]]=i;
	fore(i,0,n){
		xl[i]=a[i];
		int j=i;
		while(j>=0&&a[j]==xl[i]){xl[i]++;j--;}
		xr[i]=a[i];
		j=i;
		while(j<n&&a[j]==xr[i]){xr[i]++;j++;}
	}
	fore(i,0,7)o[i]=i;
	fore(i0,0,7)fore(j0,i0,7)fore(i1,0,7)fore(j1,i1,7)fore(i2,0,7)fore(j2,i2,7){
		memcpy(p,o,sizeof(p));memset(rv,false,sizeof(rv));
		doit(i0,j0);doit(i1,j1);doit(i2,j2);
		int k=0;
		fore(i,0,7){
			if(k==n){s[p[i]]=e[p[i]]=n;}
			else if(rv[i]){
				s[p[i]]=ai[xl[ai[k]]-1];
				e[p[i]]=ai[k]+1;
				k=xl[ai[k]];
			}
			else {
				s[p[i]]=ai[k];
				e[p[i]]=ai[xr[ai[k]]-1]+1;
				k=xr[ai[k]];
			}
		}
		if(k<n)continue;
		bool v=true;
		fore(i,0,6)if(s[i]>s[i+1]){v=false;break;}
		if(!v)continue;
		memcpy(p,o,sizeof(p));memset(rv,false,sizeof(rv));
		doit(i0,j0,true);doit(i1,j1,true);doit(i2,j2,true);
		reverse(r.begin(),r.end());
		printf("%d\n",SZ(r));
		for(auto p:r){printf("%d %d\n",p.fst+1,p.snd);}
		return 0;
	}
	assert(0);
	return 0;
}