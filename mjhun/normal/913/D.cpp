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

int n,t;
vector<pair<int,pair<int,int> > > x;
vector<int> r;

bool can(int k){
	r.clear();
	int q=0,w=0;
	for(int i=0;i<n&&q<k;++i){
		if(k<=x[i].snd.fst){
			r.pb(x[i].snd.snd);
			w+=x[i].fst;
			q++;
		}
	}
	return q==k&&w<=t;
}

int main(){
	scanf("%d%d",&n,&t);
	fore(i,0,n){
		int a,z;
		scanf("%d%d",&a,&z);
		x.pb(mp(z,mp(a,i)));
	}
	sort(x.begin(),x.end());
	int s=0,e=n+1;
	while(e-s>1){
		int m=(s+e)/2;
		if(can(m))s=m;
		else e=m;
	}
	can(s);
	printf("%d\n%d\n",s,s);
	fore(i,0,s)printf("%d%c",r[i]+1," \n"[i==s-1]);
	return 0;
}