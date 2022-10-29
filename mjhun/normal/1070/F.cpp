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

int n,a,b,c,d;
vector<int> aa,bb,cc,dd;
ll s,r;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==0)aa.pb(y),a++;
		if(x==10)bb.pb(y),b++;
		if(x==1)cc.pb(y),c++;
		if(x==11)dd.pb(y),d++;
	}
	sort(aa.begin(),aa.end());reverse(aa.begin(),aa.end());
	sort(bb.begin(),bb.end());reverse(bb.begin(),bb.end());
	sort(cc.begin(),cc.end());reverse(cc.begin(),cc.end());
	sort(dd.begin(),dd.end());reverse(dd.begin(),dd.end());
	while(SZ(cc)>SZ(bb)+d)cc.pop_back();
	while(SZ(bb)>SZ(cc)+d)bb.pop_back();
	for(int x:bb)s+=x;
	for(int x:cc)s+=x;
	for(int x:dd)s+=x;
	r=s;
	fore(i,0,min(SZ(aa),SZ(dd))){
		s+=aa[i];
		int a=i+1;
		while(SZ(cc)>SZ(bb)+d-a)s-=cc.back(),cc.pop_back();
		while(SZ(bb)>SZ(cc)+d-a)s-=bb.back(),bb.pop_back();
		r=max(r,s);
	}
	printf("%lld\n",r);
	return 0;
}