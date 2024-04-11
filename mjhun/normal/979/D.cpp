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

set<int> w[100005];

int main(){
	int q;
	scanf("%d",&q);
	while(q--){
		int t;
		scanf("%d",&t);
		if(t==1){
			int x;
			scanf("%d",&x);
			for(int i=1;i*i<=x;++i)if(x%i==0){
				w[i].insert(x);
				if(i*i!=x)w[x/i].insert(x);
			}
		}
		else {
			int x,k,s;
			scanf("%d%d%d",&x,&k,&s);
			if(x%k||w[k].empty()||*w[k].begin()+x>s){puts("-1");continue;}
			int r=0;
			for(int i=16;i>=0;--i){
				if(x&(1<<i)){
					auto it=w[k].lower_bound(r);
					if((*it)&(1<<i))r|=1<<i;
				}
				else {
					auto it=w[k].lower_bound(r|(1<<i));
					if(it==w[k].end())continue;
					int t=*it;
					if(t+x>s)continue;
					if(!(t&(1<<i)))continue;
					if((t&~((1<<(i+1))-1))!=r)continue;
					r|=1<<i;
				}
			}
			assert(r+x<=s);
			assert(w[k].count(r));
			printf("%d\n",r);
		}
	}
	return 0;
}