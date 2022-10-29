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
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int st[1<<20];

void st_upd(int k, int s, int e, int p, int v){
	if(s+1==e){st[k]=v;}
	else {
		int m=(s+e)/2;
		if(p<m)st_upd(2*k,s,m,p,v);
		else st_upd(2*k+1,m,e,p,v);
		st[k]=max(st[2*k],st[2*k+1]);
	}
}
int st_query(int k, int s, int e, int a, int v){ // mayor b tq max([a,b))<=v
	if(e<=a||st[k]<=v)return e;
	if(s+1==e)return s;
	int m=(s+e)/2;
	int r=st_query(2*k,s,m,a,v);
	if(r==m)r=st_query(2*k+1,m,e,a,v);
	return r;
}

vector<int> xs;
char qt[200005];
int qx[200005],qy[200005];
set<int> w[200005];
int m,n;

int main(){
	scanf("%d",&m);
	fore(i,0,m){
		char _s[16];
		scanf("%s%d%d",_s,qx+i,qy+i);
		qt[i]=_s[0];
		xs.pb(qx[i]);
	}
	sort(xs.begin(),xs.end());
	xs.erase(unique(xs.begin(),xs.end()),xs.end());
	n=SZ(xs);
	fore(i,0,n)w[i].insert(-1);
	fore(i,0,m)qx[i]=lower_bound(xs.begin(),xs.end(),qx[i])-xs.begin();
	mset(st,-1);
	fore(i,0,m){
		int x=qx[i],y=qy[i];
		if(qt[i]=='a'){
			w[x].insert(y);
			st_upd(1,0,n,x,*w[x].rbegin());
		}
		else if(qt[i]=='r'){
			w[x].erase(y);
			st_upd(1,0,n,x,*w[x].rbegin());
		}
		else {
			int k=st_query(1,0,n,x+1,y);
			if(k==n)puts("-1");
			else printf("%d %d\n",xs[k],*w[k].upper_bound(y));
		}
	}
	return 0;
}