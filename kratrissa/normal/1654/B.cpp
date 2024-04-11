#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,lst,cnt,ch[N<<1][26],fa[N<<1],len[N<<1],lstpos[N<<1],deg[N<<1];char s[N];queue<int> q;
void extend(int c){
	int p=lst,cur=lst=++cnt;len[cur]=len[p]+1;
	for(;p&&!ch[p][c];p=fa[p])ch[p][c]=cur;
	if(!p){fa[cur]=1;return;}
	int q=ch[p][c],nq;
	if(len[q]==len[p]+1){fa[cur]=q;return;}
	len[nq=++cnt]=len[p]+1,fa[nq]=fa[q],fa[cur]=fa[q]=nq;
	for(int i=0;i<26;i++)ch[nq][i]=ch[q][i];
	for(;p&&ch[p][c]==q;p=fa[p])ch[p][c]=nq;
}
void solve(){
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=1;i<=cnt;i++)fill(ch[i],ch[i]+26,0),fa[i]=len[i]=lstpos[i]=0;
	cnt=lst=1;
	for(int i=1,p=1;i<=n;i++)extend(s[i]-'a'),p=ch[p][s[i]-'a'],lstpos[p]=i;
	for(int i=2;i<=cnt;i++)deg[fa[i]]++;
	for(int i=1;i<=cnt;i++)if(!deg[i])q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		if(x==1)break;
		lstpos[fa[x]]=max(lstpos[fa[x]],lstpos[x]);
		if((--deg[fa[x]])==0)q.push(fa[x]);
	}
	int l=1;
	while(1){
		int r=l,p=1;
		while(lstpos[p=ch[p][s[r]-'a']]>r)r++;
		if(l==r)break;
		l=r;
	}
	for(int i=l;i<=n;i++)putchar(s[i]);putchar('\n');
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}