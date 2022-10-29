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

int n,d,s,z;
pair<int,int> r;
vector<int> c0,c1,d0,d1;

int main(){
	scanf("%d%d%d",&n,&d,&s);
	fore(i,0,n){
		int c,f,l;
		scanf("%d%d%d",&c,&f,&l);z+=c;
		if(l>=d){
			if(!c)c0.pb(f);
			else c1.pb(f);
		}
		else {
			if(!c)d0.pb(f);
			else d1.pb(f);
		}
	}
	sort(c0.begin(),c0.end());sort(c1.begin(),c1.end());
	sort(d0.begin(),d0.end());sort(d1.begin(),d1.end());
	int sf=0,k=0;
	while(k<SZ(c0)&&sf+c0[k]<=s)sf+=c0[k++];
	r=max(r,mp(k,-sf));
	if(SZ(c1)&&c1[0]<=s){
		int ss=s;
		s-=c1[0];int k=SZ(c1)+SZ(d1);
		while(k<=z&&(SZ(c0)||SZ(d0))){
			k++;
			if(SZ(d0))d0.pop_back();
			else c0.pop_back();
		}
		int t0=0,t1=1;
		while(t0<SZ(c0)||t1<SZ(c1)&&SZ(d0)){
			if(t0<SZ(c0)&&(t1==SZ(c1)||c0[t0]<c1[t1])){
				if(c0[t0]>s)break;
				s-=c0[t0++];k++;
			}
			else {
				assert(t1<SZ(c1));
				if(c1[t1]>s)break;
				s-=c1[t1++];k++;
				if(SZ(d0))d0.pop_back();
				else {
					assert(t0<SZ(c0));
					c0.pop_back();
				}
			}
		}
		r=max(r,mp(k,s-ss));
	}
	printf("%d %d\n",r.fst,-r.snd);
	return 0;
}