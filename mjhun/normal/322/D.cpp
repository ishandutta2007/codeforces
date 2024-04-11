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
#define mset(a,v) memset(a,v,sizeof(a))
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;


int n,m;
vector<int> a,d,x;

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n){
		char s[8];int z;
		scanf("%s%d",s,&z);
		if(s[0]=='A')a.pb(z);
		else d.pb(z);
	}
	fore(i,0,m){
		int z;
		scanf("%d",&z);
		x.pb(z);
	}
	sort(a.begin(),a.end());sort(d.begin(),d.end());sort(x.begin(),x.end());
	int r=0;
	fore(k,1,min(SZ(a),SZ(x))+1){
		bool v=true;int s=0;
		fore(i,0,k){
			if(a[i]>x[SZ(x)-k+i]){v=false;break;}
			s+=x[SZ(x)-k+i]-a[i];
		}
		if(!v)break;
		r=max(r,s);
	}
	bool v=true;
	multiset<int> xx(x.begin(),x.end());
	for(int z:d){
		auto it=xx.upper_bound(z);
		if(it==xx.end()){v=false;break;}
		xx.erase(it);
	}
	if(v){
		x=vector<int>(xx.begin(),xx.end());
		if(SZ(x)>=SZ(a)){
			int s=0;
			fore(i,0,SZ(a)){
				if(a[i]>x[SZ(x)-SZ(a)+i]){v=false;break;}
				s-=a[i];
			}
			for(int z:x)s+=z;
			if(v)r=max(r,s);
		}
	}
	printf("%d\n",r);
	return 0;
}