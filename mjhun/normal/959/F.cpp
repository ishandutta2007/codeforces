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
#define MOD 1000000007
using namespace std;
typedef long long ll;

int n,q;
int p2[100005];
vector<int> bb[100005];

void red(vector<int>& b){
	int i=0,j=0;
	while(i<SZ(b)&&j<20){
		int l=i;
		fore(k,i+1,SZ(b))if(b[k]&(1<<j))l=k;
		if(!(b[l]&(1<<j))){j++;continue;}
		if(l!=i)swap(b[i],b[l]);
		fore(k,0,SZ(b)){
			if(k==i)continue;
			if(b[k]&(1<<j))b[k]^=b[i];
		}
		i++;j++;
	}
	if(!b.back())b.pop_back();
	//fore(i,0,SZ(b))if((b[i]^x)<min(b[i],x))x^=b[i];
	//if(x)b.pb(x);
	//for(auto i:b)printf(" %d",i);puts("");
	//return b;
}

int main(){
	p2[0]=1;
	fore(i,1,100005)p2[i]=2*p2[i-1]%MOD;
	scanf("%d%d",&n,&q);
	bb[0]=vector<int>(0);
	fore(i,0,n){
		int x;
		scanf("%d",&x);
		bb[i+1]=bb[i];
		bb[i+1].pb(x);
		red(bb[i+1]);
	}
	while(q--){
		int l,x;
		scanf("%d%d",&l,&x);
		vector<int> a=bb[l];
		a.pb(x);
		red(a);
		if(SZ(a)>SZ(bb[l]))puts("0");
		else printf("%d\n",p2[l-SZ(bb[l])]);
	}
	return 0;
}