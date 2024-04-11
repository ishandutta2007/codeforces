#include<bits/stdc++.h>
#define N 200009
#define M 1200009
using namespace std;

int n,cnt,tot,trtot,tp,sum,q[N],fst[M],pnt[M],nxt[M],ch[M][26],ans[N][2];
bool vis[N]; char s[M];
void add(int x,int y){
	pnt[++tot]=y; nxt[tot]=fst[x]; fst[x]=tot;
}
void ins(int k,int p){
	int i,len=strlen(s+1),c;
	add(k,p);
	for (i=1; i<=len; i++){
		c=s[i]-'a';
		if (!ch[k][c]) ch[k][c]=++trtot; k=ch[k][c];
		add(k,p);
	}
}
void solve(int x,int y,int dep){
	if (!x && !y) return;
	int i,k;
	for (i=0; i<26; i++) solve(ch[x][i],ch[y][i],dep+1);
	tp=0;
	for (i=fst[x]; i; i=nxt[i]){
		k=pnt[i];
		if (!vis[k]) q[++tp]=k;
	}
	for (i=fst[y]; i && tp; i=nxt[i]){
		k=pnt[i];
		if (!vis[k]){
			sum+=dep;
			ans[++cnt][0]=q[tp]; ans[cnt][1]=k-n;
			vis[q[tp--]]=vis[k]=1;
		}
	}
}
int main(){
	scanf("%d",&n);
	int i;
	trtot=2;
	for (i=1; i<=n; i++){
		scanf("%s",s+1);
		ins(1,i);
	}
	for (i=1; i<=n; i++){
		scanf("%s",s+1);
		ins(2,i+n);
	}
	solve(1,2,0);
	printf("%d\n",sum);
	for (i=1; i<=cnt; i++) printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}