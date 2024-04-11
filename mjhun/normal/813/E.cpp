#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

struct ST {
	vector<int> st,l,r;int n,rt,sz;
	ST(int n):n(n),rt(0),st(44*n,0),l(44*n,0),r(44*n,0),sz(1){}
	ST(){}
	int upd(int k, int s, int e, int p, int v){
		int nk=sz++;l[nk]=l[k];r[nk]=r[k];
		if(s+1==e)st[nk]=v;
		else {
			int m=(s+e)/2;
			if(p<m)l[nk]=upd(l[k],s,m,p,v);
			else r[nk]=upd(r[k],m,e,p,v);
			st[nk]=st[l[nk]]+st[r[nk]];
		}
		return nk;
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return 0;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return query(l[k],s,m,a,b)+query(r[k],m,e,a,b);
	}
	int upd(int k, int p, int v){return rt=upd(k,0,n,p,v);}
	int upd(int p, int v){return upd(rt,p,v);}
	int query(int k, int a, int b){return query(k,0,n,a,b);}
};

int n,k;
ST st;
vector<int> w[100005];
int rt[100005];

int main(){
	scanf("%d%d",&n,&k);
	st=ST(n);
	fore(i,0,n){
		int x;
		scanf("%d",&x);x--;
		w[x].pb(i);
		if(w[x].size()>k){
			int j=w[x][w[x].size()-k-1];
			st.upd(j,0);
		}
		rt[i]=st.upd(i,1);
	}
	int q,l=0;
	scanf("%d",&q);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		int a=(x+l)%n+1;
		int b=(y+l)%n+1;
		if(a>b)swap(a,b);
		a--;
		l=st.query(rt[b-1],a,b);
		printf("%d\n",l);
	}
	return 0;
}