#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

#define oper(a,b) (a+b)
#define NEUT 0
struct STree {
	vector<int> st,l,r;int n,sz,rt;
	STree(int n): st(64*n,NEUT), l(64*n,0), r(64*n,0), n(n), rt(0), sz(1) {}
	STree(){}
	int upd(int k, int s, int e, int p, int v){
		int nk=sz++;l[nk]=l[k];r[nk]=r[k];
		if(s+1==e){st[nk]=v;return nk;}
		int m=(s+e)/2;
		if(p<m)l[nk]=upd(l[k],s,m,p,v);
		else r[nk]=upd(r[k],m,e,p,v);
		st[nk]=oper(st[l[nk]],st[r[nk]]);
		return nk;
	}
	int query(int k, int s, int e, int q){ // where is qth 1
		if(s+1==e){
			if(q==1&&st[k])return s;
			return e;
		}
		int m=(s+e)/2;
		if(st[l[k]]>=q)return query(l[k],s,m,q);
		return query(r[k],m,e,q-st[l[k]]);
	}
	int upd(int k, int p, int v){return rt=upd(k,0,n,p,v);}
	int upd(int p, int v){return upd(rt,p,v);}
	int query(int k, int q){return query(k,0,n,q);}
};

STree st;
int n;
int x[100005];
int w[100005];
int rt[100005];

int doit(int k){
	int i=0,r=0;
	while(i<n){
		i=st.query(rt[i],k+1);
		r++;
	}
	return r;
}

int main(){
	scanf("%d",&n);st=STree(n);
	fore(i,0,n)scanf("%d",x+i),x[i]--;
	memset(w,-1,sizeof(w));
	for(int i=n-1;i>=0;--i){
		if(w[x[i]]>=0)st.upd(w[x[i]],0);
		rt[i]=st.upd(i,1);
		w[x[i]]=i;
	}
	fore(k,1,n+1){
		if(k>1)putchar(' ');
		printf("%d",doit(k));
	}
	puts("");
	return 0;
}