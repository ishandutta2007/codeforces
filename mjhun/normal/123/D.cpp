#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

struct state {
	int len,link;
	map<char,int> next;
};

const int MAXLEN=100005;
state st[MAXLEN*2];
bool e[MAXLEN*2];
int sz,last;
vector<int> g[MAXLEN*2];

void sa_init(){
	sz=last=0;
	st[0].len=0;
	st[0].link=-1;
	++sz;
}

void sa_extend (char c) {
	int cur=sz++;
	st[cur].len=st[last].len+1;
	int p;
	for(p=last;p!=-1&&!st[p].next.count(c);p=st[p].link)
		st[p].next[c]=cur;
	if(p==-1)
		st[cur].link=0;
	else {
		int q=st[p].next[c];
		if(st[p].len+1==st[q].len)
			st[cur].link=q;
		else {
			int clone=sz++;
			st[clone].len=st[p].len+1;
			st[clone].next=st[q].next;
			st[clone].link=st[q].link;
			for(;p!=-1&&st[p].next[c]==q;p=st[p].link)
				st[p].next[c]=clone;
			st[q].link=st[cur].link=clone;
		}
	}
	last=cur;
}

char s[MAXLEN];
int dp[MAXLEN*2];
int dp2[MAXLEN*2];
int n;

int f(int x){
	if(dp[x]>=0)return dp[x];
	dp[x]=e[x];
	for(map<char,int>::iterator it=st[x].next.begin();it!=st[x].next.end();++it){
		dp[x]+=f(it->snd);
	}
	return dp[x];
}

int f2(int x){
	if(dp2[x]>=0)return dp2[x];
	dp2[x]=0;
	fore(i,0,g[x].size()){
		dp2[x]+=f2(g[x][i]);
	}
	return dp2[x];
}

int main(){
	scanf("%s",s);n=strlen(s);
	sa_init();
	fore(i,0,n){
		sa_extend(s[i]);
	}
	for(int i=last;i>=0;i=st[i].link)e[i]=true;
	fore(i,0,sz){
		for(map<char,int>::iterator it=st[i].next.begin();it!=st[i].next.end();++it){
			g[it->snd].pb(i);
		}
	}
	memset(dp,-1,sizeof(dp));
	memset(dp2,-1,sizeof(dp2));
	dp2[0]=1;
	ll r=0;
	fore(i,1,sz){
		r+=1LL*f(i)*(f(i)+1)*f2(i)/2;
	}
	cout<<r<<endl;
	return 0;
}