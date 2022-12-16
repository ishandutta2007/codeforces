#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<int> V;

template<class T=int>
T read(){
	T x=0;
	char ch=0;
	bool f=false;
	while(!isdigit(ch))f|=(ch=getchar())=='-';
	for(;isdigit(ch);ch=getchar())x=x*10+(ch^'0');
	return f?-x:x;
}

const int N=5.1e5;
const int C=26;

namespace SAM{

const int N=::N*2;
struct Node{
	int ch[C],fa;
	int len;
}o[N];
int nid=0;
int rt=++nid;
int last=rt;
int split(int l,int c){
	int p=o[l].ch[c];
	if(o[p].len==o[l].len+1)return p;
	int q=++nid;
	o[q]=o[p];
	o[q].len=o[l].len+1;
	o[p].fa=q;
	for(;l&&o[l].ch[c]==p;l=o[l].fa)o[l].ch[c]=q;
	return q;
}
void add(int c){
	int l=last;
	int x=++nid;
	o[x].len=o[l].len+1;
	for(;l&&!o[l].ch[c];l=o[l].fa)o[l].ch[c]=x;
	o[x].fa=l?split(l,c):rt;
	last=x;
}
int id[N];
int cnt[::N];
void sort(){
	F(i,1,nid)cnt[o[i].len]++;
	int len=o[last].len;
	F(i,1,len)cnt[i]+=cnt[i-1];
	F(i,1,nid)id[cnt[o[i].len]--]=i;
}

}

int n;
namespace SegTree{

const int S=40*N;
struct Node{
	int l,r;
}o[S];
int nid=0;
int add(int rt,int pos,int ll,int rr){
	int x=++nid;
	o[x]=o[rt];
	if(ll!=rr){
		int mid=(ll+rr)>>1;
		if(pos<=mid)o[x].l=add(o[rt].l,pos,ll,mid);
		else o[x].r=add(o[rt].r,pos,mid+1,rr);
	}
	return x;
}
int add(int rt,int pos){return add(rt,pos,1,n);}
int merge(int a,int b){
	if(!a)return b;
	if(!b)return a;
	int x=++nid;
	o[x].l=merge(o[a].l,o[b].l);
	o[x].r=merge(o[a].r,o[b].r);
	return x;
}
int query(int rt,int pos,int ll,int rr){
	if(!rt||pos<ll)return -1;
	if(ll==rr)return ll;
	int mid=(ll+rr)>>1;
	int la=query(o[rt].r,pos,mid+1,rr);
	return la!=-1?la:query(o[rt].l,pos,ll,mid);
}
int query(int rt,int pos){return query(rt,pos,1,n);}

void debug(int rt,int ll,int rr){
	if(ll==rr)cerr<<ll<<" ";
	else{
		int mid=(ll+rr)>>1;
		if(o[rt].l)debug(o[rt].l,ll,mid);
		if(o[rt].r)debug(o[rt].r,mid+1,rr);
	}
}
void debug(int rt){
	debug(rt,1,n);
	cerr<<endl;
}

}

int rt[SAM::N];
int exep[SAM::N];
int fch[SAM::N][C];

char s[N];
int ep[SAM::N];
int tep[SAM::N];
int nd[10*N];
int main(){
	n=read();
	scanf("%s",s+1);
	F(i,1,n){
		SAM::add(s[i]-'a');
		int l=SAM::last;
		rt[l]=SegTree::add(rt[l],i);
		exep[l]=i;
	}
	SAM::sort();
	R(i,SAM::nid,2){
		int x=SAM::id[i];
		int f=SAM::o[x].fa;
		rt[f]=SegTree::merge(rt[f],rt[x]);
		exep[f]=exep[x];
		// cerr<<x<<" "<<f<<endl;
		fch[f][s[exep[x]-SAM::o[f].len]-'a']=x;
	}
	// debug();

	int len=-1;
	int l=0,r=0;
	int nal=r;
	nd[r++]=SAM::rt;
	tep[SAM::rt]=n;
	while(l!=r){
		if(l==nal){
			len++;
			nal=r;
			F(i,l,r-1){
				ep[nd[i]]=tep[nd[i]];
				tep[nd[i]]=0;
			}
		}
		int x=l++;
		int v=nd[x];
		// cerr<<"len="<<len<<endl;
		int e=ep[v];
		int s=e-len;
		// cerr<<"v="<<v<<" ep="<<e<<" str="<<string(::s+s+1,::s+e+1)<<endl;
		V ps;
		D(i,C){
			int p=SAM::o[v].ch[i];
			if(p)ps.push_back(p);
		}
		if(len!=SAM::o[v].len){
			ps.push_back(v);
		}
		else{
			D(i,C){
				int p=fch[v][i];
				if(p)ps.push_back(p);
			}
		}
		D(i,ps.size()){
			int p=ps[i];
			int qwq=SegTree::query(rt[p],s);
			if(!tep[p]&&qwq!=-1)nd[r++]=p;
			tep[p]=max(tep[p],qwq);
		}
	}
	// cerr<<r<<endl;
	printf("%d\n",len);
	return 0;
}