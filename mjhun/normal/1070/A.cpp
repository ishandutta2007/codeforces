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

int pt[505][5005],pd[505][5005];
int d,s;
queue<pair<int,int> > q;
vector<int> r;

int main(){
	scanf("%d%d",&d,&s);
	mset(pt,-1);
	pt[0][s]=0;
	q.push(mp(0,s));
	while(!q.empty()){
		int t=q.front().fst,s=q.front().snd;q.pop();
		fore(i,0,10){
			int tt=(t*10+i)%d,ss=s-i;
			if(ss<0)break;
			if(pt[tt][ss]<0){
				pt[tt][ss]=t;
				pd[tt][ss]=i;
				q.push(mp(tt,ss));
			}
		}
	}
	if(pt[0][0]<0){puts("-1");return 0;}
	int a=0,b=0;
	while(b<s){
		int t=pd[a][b];
		r.pb(t);
		a=pt[a][b];
		b+=t;
	}
	reverse(r.begin(),r.end());
	for(int t:r)printf("%d",t);puts("");
	return 0;
}