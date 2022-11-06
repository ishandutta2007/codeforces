#include<bits/stdc++.h>
#define ll long long
#define N 100009
using namespace std;

int n,m,L,tp,q[99],ans;
char s[99],s0[99];
struct hsh{
	int tot,fst[20000003]; ll px[N],py[N]; int sz[N],pl[N],nxt[N];
	int tp,q[N],h[N];
	void clr(){
		for (; tp; tp--) sz[q[tp]]=h[tp];
	}
	void ins(ll x,ll y,int len){
		int i,z=((x/123)+y+len*233ll)%2000003;
		for (i=fst[z]; i; i=nxt[i])
			if (px[i]==x && py[i]==y && pl[i]==len){
				sz[i]++; return;
			}
		px[++tot]=x; py[tot]=y; pl[tot]=len; nxt[tot]=fst[z];sz[tot]=1; fst[z]=tot;
	}
	int calc(ll x,ll y,int len){
		int i,z=((x/123)+y+len*233ll)%2000003;
		for (i=fst[z]; i; i=nxt[i])
			if (px[i]==x && py[i]==y && pl[i]==len){
				q[++tp]=i; h[tp]=sz[i]; sz[i]=0;
				return h[tp];
			}
		return 0;
	}
}hsh;
int calc(){
	int i,j,len=0; ll x=0,y=0;
	for (i=1; i<=L; i++) if (s[i]<='e') s0[++len]=s[i];
	for (j=1; j<=25 && j<=len; j++) x=x*5+s0[j]-'a';
	for (j=1; j<=25 && 25+j<=len; j++) y=y*5+s0[25+j]-'a';
	return hsh.calc(x,y,len);
}
void dfs(int x){
	if (x>tp){
		ans+=calc(); return;
	}
	char ch;
	for (ch='a'; ch<='f'; ch++){ s[q[x]]=ch; dfs(x+1); }
}
int main(){
	scanf("%d%d",&n,&m);
	int i,j;
	for (i=1; i<=n; i++){
		scanf("%s",s+1);
		int len=strlen(s+1); ll x=0,y=0;
		for (j=1; j<=25 && j<=len; j++) x=x*5+s[j]-'a';
		for (j=1; j<=25 && 25+j<=len; j++) y=y*5+s[25+j]-'a';
		//	cout<<x<<' '<<y<<' '<<len<<endl;
		hsh.ins(x,y,len);
	}
	for (i=1; i<=m; i++){
		hsh.clr();
		scanf("%s",s+1);
		L=strlen(s+1);
		for (j=1,tp=0; j<=L; j++) if (s[j]=='?') q[++tp]=j;
		//	cout<<tp<<endl;
		ans=0; dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}