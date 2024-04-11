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


struct state {int len,link,fp;int next[2];};
state st[1<<20];
int sz,last;
void sa_init(){
	last=st[0].len=0;sz=1;
	st[0].link=-1;
}
void sa_extend(char c){
	int k=sz++,p;
	st[k].len=st[last].len+1;
	st[k].fp=st[k].len;
	for(p=last;p!=-1&&!st[p].next[c];p=st[p].link)st[p].next[c]=k;
	if(p==-1)st[k].link=0;
	else {
		int q=st[p].next[c];
		if(st[p].len+1==st[q].len)st[k].link=q;
		else {
			int w=sz++;
			st[w].len=st[p].len+1;
			st[w].next[0]=st[q].next[0];
			st[w].next[1]=st[q].next[1];
			st[w].link=st[q].link;
			st[w].fp=st[q].fp;
			for(;p!=-1&&st[p].next[c]==q;p=st[p].link)st[p].next[c]=w;
			st[q].link=st[k].link=w;
		}
	}
	last=k;
}

int n;
char ss[1<<19];
vector<int> w[1<<20];
int s[1<<19];
#define O (1<<19)

int main(){
	scanf("%d%s",&n,ss);
	sa_init();
	for(int i=n-1;i>=0;--i)sa_extend(ss[i]==')');
	s[0]=O;
	w[s[0]].pb(0);
	fore(i,0,n){
		s[i+1]=s[i]+(ss[i]=='('?1:-1);
		w[s[i+1]].pb(i+1);
	}
	ll r=0;
	fore(i,1,sz){
		int a=n-st[i].fp;
		int b=a+st[st[i].link].len+1;
		auto it=upper_bound(w[s[a]-1].begin(),w[s[a]-1].end(),a);
		int c;
		if(it==w[s[a]-1].end())c=n+1;
		else c=*it;
		c=min(c,a+st[i].len+1);
		// [b,c)
		if(b>=c)continue;
		int t=lower_bound(w[s[a]].begin(),w[s[a]].end(),c)-lower_bound(w[s[a]].begin(),w[s[a]].end(),b);
		r+=t;
		//printf(" %d  %d %d %d %d\n",i,a,b,c,t);
	}
	printf("%lld\n",r);
	return 0;
}