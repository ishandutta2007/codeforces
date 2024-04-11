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

set<pair<int,int> > v;
priority_queue<pair<ll,pair<int,int> > > q;
int n,m,r,k;
ll rr;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

ll f(int x, int y){
	int x0=max(x-r+1,0),x1=min(x,n-r);
	int y0=max(y-r+1,0),y1=min(y,m-r);
	return 1LL*(x1-x0+1)*(y1-y0+1);
}

int main(){
	scanf("%d%d%d%d",&n,&m,&r,&k);
	q.push(mp(f(n/2,m/2),mp(n/2,m/2)));
	v.insert(mp(n/2,m/2));
	while(k){
		auto p=q.top();q.pop();
		rr+=p.fst;
		int x=p.snd.fst,y=p.snd.snd;
		fore(_,0,4){
			int xx=x+dx[_],yy=y+dy[_];
			if(!v.count(mp(xx,yy))&&xx>=0&&xx<n&&yy>=0&&yy<m){
				v.insert(mp(xx,yy));
				q.push(mp(f(xx,yy),mp(xx,yy)));
			}
		}
		k--;
	}
	printf("%.12lf\n",(double)(1.l*rr/(1LL*(n-r+1)*(m-r+1))));
	return 0;
}