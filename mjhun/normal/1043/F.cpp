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

int gcd(int a, int b){
	while(b){
		int c=a%b;
		a=b;b=c;
	}
	return a;
}

int n;
int p[300005];
int d[300005];
int q[300005];
queue<int> qq;
vector<int> ds[300005];
bool ok[300005];
set<int> pingo;

int main(){
	mset(p,-1);
	fore(i,2,300005)if(p[i]<0)for(int j=i;j<300005;j+=i)p[j]=i;
	fore(i,2,300005)for(int j=i;j<300005;j+=i)ds[j].pb(i);
	/*int t=0;
	for(int i=2;i<300005;i++){
		int a=i,x=1;
		while(a>1){
			int q=p[a];x*=q;
			while(a%q==0)a/=q;
		}
		if(i==x)t++;
	}
	printf("%d\n",t);
	*/
	scanf("%d",&n);
	int g=0;
	fore(i,0,n){
		int a,x=1;
		scanf("%d",&a);
		while(a>1){
			int q=p[a];x*=q;
			while(a%q==0)a/=q;
		}
		a=x;
		g=gcd(g,a);
		for(int x:ds[a])q[x]++;
		pingo.insert(a);
	}
	fore(i,2,300005){
		int a=i,x=1;
		vector<int> t;
		while(a>1){
			int q=p[a];x*=q;
			while(a%q==0)a/=q;
			t.pb(q);
		}
		if(x!=i)continue;
		int s=0;
		fore(m,1,1<<SZ(t)){
			int z=1,w=0;
			fore(j,0,SZ(t)){
				if((m>>j)&1)z*=t[j],w++;
			}
			if(w&1)s+=q[z];
			else s-=q[z];
		}
		ok[i]=s!=n;
	}
	mset(d,-1);
	for(int x:pingo)d[x]=1,qq.push(x);
	while(!qq.empty()){
		int x=qq.front();qq.pop();
		for(int i:ds[x])if(ok[i]){
			int y=x/i;
			if(d[y]<0)d[y]=d[x]+1,qq.push(y);
		}
	}
	printf("%d\n",d[1]);
	return 0;
}