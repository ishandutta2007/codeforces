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
int l[128],r[128];
vector<pair<int,int> > w;
bool vis[128];

int main(){
	scanf("%d",&n);
	fore(i,0,n){scanf("%d%d",l+i,r+i);l[i]--;r[i]--;}
	fore(i,0,n){
		if(vis[i])continue;
		int k=i;
		vis[k]=true;
		while(l[k]>=0){
			k=l[k];
			vis[k]=true;
		}
		int a=k;
		k=i;
		while(r[k]>=0){
			k=r[k];
			vis[k]=true;
		}
		int b=k;
		w.pb(mp(a,b));
	}
	fore(i,0,w.size()-1){
		r[w[i].snd]=w[i+1].fst;
		l[w[i+1].fst]=w[i].snd;
	}
	fore(i,0,n)printf("%d %d\n",l[i]+1,r[i]+1);
	return 0;
}