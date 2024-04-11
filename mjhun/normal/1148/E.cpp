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

int n;
pair<int,int> z[300005];int s[300005],t[300005];ll ss,st;
vector<pair<pair<int,int>,int> > r;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int a;
		scanf("%d",&a);ss+=a;z[i]=mp(a,i);
	}
	fore(i,0,n)scanf("%d",t+i),st+=t[i];
	if(ss!=st){puts("NO");return 0;}
	sort(z,z+n);sort(t,t+n);
	fore(i,0,n)s[i]=z[i].fst;
	int j=0;
	fore(i,0,n){
		if(s[i]>t[i]){puts("NO");return 0;}
		j=max(j,i+1);
		while(s[i]<t[i]){
			while(s[j]<=t[j])j++;
			int d=min(t[i]-s[i],s[j]-t[j]);
			r.pb(mp(mp(z[i].snd,z[j].snd),d));
			s[i]+=d;s[j]-=d;
		}
	}
	printf("YES\n%d\n",SZ(r));
	for(auto p:r)printf("%d %d %d\n",p.fst.fst+1,p.fst.snd+1,p.snd);
	return 0;
}