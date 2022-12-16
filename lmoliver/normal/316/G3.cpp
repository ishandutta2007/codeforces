#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<int> V;

template<class T=int>
T read(){
	T x=0;
	char ch=0;
	bool f=false;
	while(!isdigit(ch))f|=(ch=getchar())=='-';
	for(;isdigit(ch);ch=getchar())x=x*10+(ch^'0');
	return x;
}

const int X=11;
const int C=26;
struct Node;
typedef Node *np;
struct Node{
	np ch[C];
	np link;
	int len;
	int cnt[X];
};

const int S=1212121;
Node mem[S];
np st=mem;
np newNode(){
	return st++;
}
int f(np x){
	return x?x-mem:-1;
}

np rt=newNode();
np last;
void extend(int c,int id){
	if(last&&last->ch[c]&&last->ch[c]->len==last->len+1){
		last=last->ch[c];
		last->cnt[id]++;
		return;
	}
	np p=last;
	np nd=newNode();
	nd->cnt[id]=1;
	nd->len=last->len+1;
	last=nd;
	for(;p&&!p->ch[c];p=p->link)p->ch[c]=nd;
	if(!p){
		nd->link=rt;
		return;
	}
	np q=p->ch[c];
	if(q->len==p->len+1){
		nd->link=q;
	}
	else{
		np x=newNode();
		x->len=p->len+1;
		x->link=q->link;
		memcpy(x->ch,q->ch,sizeof(Node::ch));
		nd->link=x;
		q->link=x;
		for(;p&&p->ch[c]==q;p=p->link){
			p->ch[c]=x;
		}
	}
}

const int N=50505;
char s[N];
void ins(int id){
	scanf("%s",s);
	// cerr<<"ins "<<id<<" "<<s<<endl;
	last=rt;
	for(int i=0;s[i];i++){
		extend(s[i]-'a',id);
	}
}
vector<np> tmp[N];
int l[X],r[X];
string example[N];
void dfs(np rt,string pre=""){
	if(!rt)return;
	if((int)pre.size()==rt->len)example[f(rt)]=pre;
	D(i,C)dfs(rt->ch[i],pre+(char)('a'+i));
}
int main(){
	ins(0);
	l[0]=1,r[0]=1e9;
	int n=read();
	F(i,1,n){
		ins(i);
		l[i]=read();
		r[i]=read();
	}
	int mx=0;
	for(np p=mem;p<st;p++){
		tmp[p->len].push_back(p);
		mx=max(mx,p->len);
	}
	LL ans=0;
	// dfs(rt);
	for(int i=mx;i>=1;i--){
		for(np p:tmp[i]){
			// cerr<<"("<<p->len<<") "<<example[f(p)]<<" link="<<example[f(p->link)];
			// F(i,0,n)cerr<<" ["<<i<<"]:"<<p->cnt[i];
			// cerr<<endl;
			assert(p->link->len!=-1);
			bool ok=true;
			F(i,0,n){
				p->link->cnt[i]+=p->cnt[i];
				ok&=p->cnt[i]>=l[i]&&p->cnt[i]<=r[i];
			}
			if(ok)ans+=p->len-p->link->len;
			p->len=-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}