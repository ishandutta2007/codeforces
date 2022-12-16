#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=(int)(0);N<(int)(E);N++)
typedef vector<int> V;
int _;
LL read(){LL x;_=scanf("%lld",&x);return x;}

const int N=5.1e5+5.1e4;
const int L=20;
const int C=26;

namespace SAM{

struct Node{
	int ch[C],fa;
	int len;
}o[2*N];
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
	if(o[l].ch[c])last=split(l,c);
	else{
		int x=++nid;
		o[x].len=o[l].len+1;
		last=x;
		for(;l&&!o[l].ch[c];l=o[l].fa)o[l].ch[c]=x;
		o[x].fa=l?split(l,c):rt;
	}
}

string s;
bool dfs(int x,int t,int len){
	if(x==t&&(int)s.size()==len)return true;
	D(i,C){
		s+=(char)('a'+i);
		if(o[x].ch[i]&&dfs(o[x].ch[i],t,len))return true;
		s.pop_back();
	}
	return false;
}
string debug(int x){
	s="";
	dfs(rt,x,o[o[x].fa].len+1);
	string s1=s;
	s="";
	dfs(rt,x,o[x].len);
	string s2=s;
	stringstream ss;
	ss<<"["<<s1<<","<<s2<<"]_len="<<o[x].len;
	string ans;
	ss>>ans;
	return ans;
}

}

namespace SegTree{

struct Data{
	int cnt,id;
};
bool operator<(Data a,Data b){return a.cnt!=b.cnt?a.cnt<b.cnt:a.id>b.id;}
const int S=2*N*L;
struct Node{
	Data v;
	int l,r;
}o[S];
int nid=0;

int add(int pos,int ll,int rr,int id){
	int v=++nid;
	o[v]=o[id];
	if(ll==rr){
		o[v].v.id=ll;
		o[v].v.cnt++;
	}
	else{
		int mid=(ll+rr)>>1;
		if(pos<=mid)o[v].l=add(pos,ll,mid,o[v].l);
		else o[v].r=add(pos,mid+1,rr,o[v].r);
		o[v].v=max(o[o[v].l].v,o[o[v].r].v);
	}
	assert(o[v].v.cnt>=0);
	return v;
}
Data query(int l,int r,int ll,int rr,int id){
	if(!id||ll>r||rr<l)return o[0].v;
	if(ll>=l&&rr<=r)return o[id].v;
	int mid=(ll+rr)>>1;
	return max(query(l,r,ll,mid,o[id].l),query(l,r,mid+1,rr,o[id].r));
}
int merge(int a,int b){
	if(!a)return b;
	if(!b)return a;
	int v=++nid;
	o[v].l=merge(o[a].l,o[b].l);
	o[v].r=merge(o[a].r,o[b].r);
	if(o[v].l||o[v].r){
		o[v].v=max(o[o[v].l].v,o[o[v].r].v);
	}
	else{
		assert(o[a].v.id==o[b].v.id);
		o[v].v=o[a].v;
		o[v].v.cnt+=o[b].v.cnt;
	}
	return v;
}
void debug(int ll,int rr,int id){
	if(!id)return;
	if(ll==rr)cerr<<"id="<<o[id].v.id<<" cnt="<<o[id].v.cnt<<endl;
	else{
		int mid=(ll+rr)>>1;
		debug(ll,mid,o[id].l);
		debug(mid+1,rr,o[id].r);
	}
}

}

int fas[2*N][L];
int tr[2*N];
int ids[N];
char ss[N];
V es[2*N];
void dfs(int x){
	F(j,1,L-1)fas[x][j]=fas[fas[x][j-1]][j-1];
	D(i,es[x].size()){
		int v=es[x][i];
		dfs(v);
		tr[x]=SegTree::merge(tr[x],tr[v]);
	}
}

int main(){
	_=scanf("%s",ss);
	int m=strlen(ss);
	D(i,m){
		SAM::add(ss[i]-'a');
		ids[i+1]=SAM::last;
	}
	int n=read();
	F(i,1,n){
		_=scanf("%s",ss);
		int m=strlen(ss);
		SAM::last=SAM::rt;
		D(j,m){
			SAM::add(ss[j]-'a');
			tr[SAM::last]=SegTree::add(i,1,n,tr[SAM::last]);
		}
	}
	F(i,2,SAM::nid){
		fas[i][0]=SAM::o[i].fa;
		es[fas[i][0]].push_back(i);
	}
	dfs(SAM::rt);
	// F(i,1,SAM::nid){
	// 	cerr<<"#"<<i<<":"<<endl;
	// 	cerr<<SAM::debug(i)<<endl;
	// 	SegTree::debug(1,n,tr[i]);
	// }
	int q=read();
	D(_,q){
		int l=read(),r=read(),pl=read(),pr=read();
		int id=ids[pr];
		int len=pr-pl+1;
		R(i,L-1,0)if(SAM::o[fas[id][i]].len>=len)id=fas[id][i];
		// cerr<<"sam #"<<id<<":"<<id<<endl;
		SegTree::Data ans=SegTree::query(l,r,1,n,tr[id]);
		if(ans.cnt==0)ans.id=l;
		printf("%d %d\n",ans.id,ans.cnt);
	}
	return 0;
}