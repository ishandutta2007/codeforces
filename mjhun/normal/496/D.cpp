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
#define mset(x,a) (memset((x),(a),sizeof(x)))
#define mcpy(x,y) (memcpy((x),(y),sizeof(x)))
using namespace std;
typedef long long ll;

int n,a[100005],b[100005];


int doit(int t){
	bool asd;int sa=0,sb=0;
	for(int i=0;i<n;){
		int ai=lower_bound(a,a+n+1,a[i]+t)-a;
		int bi=lower_bound(b,b+n+1,b[i]+t)-b;
		if(ai==n+1&&bi==n+1)return -1;
		if(ai<bi){
			i=ai;
			sa++;
			asd=true;
		}
		else {
			i=bi;
			sb++;
			asd=false;
		}
	}
	if(asd){
		if(sa<=sb)return -1;
		return sa;
	}
	else {
		if(sb<=sa)return -1;
		return sb;
	}
}

vector<pair<int,int> > r;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int t;
		scanf("%d",&t);
		if(t==1)a[i+1]=1;
		else b[i+1]=1;
	}
	fore(i,0,n)a[i+1]+=a[i],b[i+1]+=b[i];
	fore(t,1,n+1){
		int s=doit(t);
		if(s>0)r.pb(mp(s,t));
	}
	sort(r.begin(),r.end());
	printf("%d\n",SZ(r));
	for(auto p:r)printf("%d %d\n",p.fst,p.snd);
	return 0;
}