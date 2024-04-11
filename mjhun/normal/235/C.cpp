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

struct state {int len,link;map<char,int> next;};
state st[1<<21];
int sz,last;
void sa_init(){
	last=st[0].len=0;sz=1;
	st[0].link=-1;
}
void sa_extend(char c){
	int k=sz++,p;
	st[k].len=st[last].len+1;
	for(p=last;p!=-1&&!st[p].next.count(c);p=st[p].link)st[p].next[c]=k;
	if(p==-1)st[k].link=0;
	else {
		int q=st[p].next[c];
		if(st[p].len+1==st[q].len)st[k].link=q;
		else {
			int w=sz++;
			st[w].len=st[p].len+1;
			st[w].next=st[q].next;st[w].link=st[q].link;
			for(;p!=-1&&st[p].next[c]==q;p=st[p].link)st[p].next[c]=w;
			st[q].link=st[k].link=w;
		}
	}
	last=k;
}

bool fin[1<<21];
int dp[1<<21];
bool vis[1<<21];vector<int> vv;

char s[1<<21];
int q;

int f(int x){
	int& r=dp[x];
	if(r>=0)return r;
	r=fin[x];
	for(auto p:st[x].next)r+=f(p.snd);
	return r;
}

int main(){
	scanf("%s",s);
	sa_init();
	for(int i=0;s[i];++i)sa_extend(s[i]);
	for(int i=last;i>=0;i=st[i].link)fin[i]=true;
	mset(dp,-1);
	scanf("%d",&q);
	while(q--){
		scanf("%s",s);
		int n=strlen(s);
		fore(i,0,n)s[n+i]=s[i];
		int a=0,b=0,k=0;int r=0;
		while(b<2*n){
			if(b-a==n){
				if(vis[k])break;
				vis[k]=true;
				vv.pb(k);
				r+=f(k);
			}
			if(b-a<n&&st[k].next.count(s[b])){
				k=st[k].next[s[b]];
				b++;
			}
			else {
				if(a==b)break;
				a++;
				if(st[st[k].link].len>=b-a)k=st[k].link;
			}
		}
		printf("%d\n",r);
		for(int t:vv)vis[t]=false;
		vv.clear();
	}
	return 0;
}