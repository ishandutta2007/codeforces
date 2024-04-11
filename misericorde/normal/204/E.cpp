#include <bits/stdc++.h>
#define maxn 500005
char s[maxn];
int n,k,belong[maxn],endpos[maxn],ch[maxn<<3][2]={0},size[maxn<<3]={0},tag[maxn<<2]={0},tail=0;
long long ans[maxn]={0};
const int inf=1e8;
struct suffixTree {
    int start[maxn<<1],len[maxn<<1],link[maxn<<1],s[maxn],
    tail,n,rem,now;
    std::map <int,int> ch[maxn<<1];
    suffixTree ():tail(1),n(0),rem(0),now(1) {len[0]=inf;}
    int newnode(int st,int l) {start[++tail]=st;len[tail]=l;link[tail]=1;return tail;}
    void extend(int x) {
        s[++n]=x;rem++;
        for (int last=1;rem;) {
            while (rem>len[ch[now][s[n-rem+1]]]) rem-=len[now=ch[now][s[n-rem+1]]];
            int ed=s[n-rem+1];int &v=ch[now][ed];int c=s[start[v]+rem-1];
            if (!v||x==c) {
                link[last]=now; last=now;
                if (!v) {v=newnode(n-rem+1,inf);}
                else break;
            } else {
                int u=newnode(start[v],rem-1);
                ch[u][x]=newnode(n,inf);
                ch[u][c]=v,start[v]+=rem-1,len[v]-=rem-1;
                link[last]=v=u,last=v;
            }if (now==1) --rem; else now=link[now];
        }
    }
}sft;

void update(int rt) {
	if (ch[rt][0]||ch[rt][1]) size[rt]=size[ch[rt][0]]+size[ch[rt][1]];
	else size[rt]=1;
}

int merge(int u,int v) {
	//printf("merge %d %d\n",u,v);
	if (!u||!v) return u+v;
	ch[u][0]=merge(ch[u][0],ch[v][0]);
	ch[u][1]=merge(ch[u][1],ch[v][1]);
	update(u); return u;
}

int insert(int rt,int l,int r,int p) {
	//printf("insert %d %d %d %d\n",rt,l,r,p);
	if (!rt) rt=++tail;
	if (l==r) {size[rt]=1;return rt;}
	int mid=(l+r)>>1;
	if (p<=mid) ch[rt][0]=insert(ch[rt][0],l,mid,p);
	else ch[rt][1]=insert(ch[rt][1],mid+1,r,p);
	update(rt);
	return rt;
}

int dfs(int u) {
    int length=std::min((endpos[belong[sft.start[u]]]-sft.start[u]+1),sft.len[u]),isleaf=1;
    std::map<int,int>::iterator iter;
    iter=sft.ch[u].begin();
    int now=0;
    while (iter!=sft.ch[u].end()) {
        int v=iter->second; now=merge(now,dfs(v)); 
		isleaf=0;iter++;
    }
    
    if (isleaf) now=insert(now,1,n,belong[sft.start[u]]);
	
	if (size[now]>=k) tag[u]=length;
    return now;
}

void dfs2(int u,int det) {
    int length=std::min((endpos[belong[sft.start[u]]]-sft.start[u]+1),sft.len[u]),isleaf=1;
    std::map<int,int>::iterator iter;
    iter=sft.ch[u].begin();
    while (iter!=sft.ch[u].end()) {
        int v=iter->second; 
        dfs2(v,det+tag[v]);
		isleaf=0;iter++;
    }if (isleaf) ans[belong[sft.start[u]]]+=det;
}
    	
//luogu judger again

int main() {
    scanf("%d%d",&n,&k); int last=1;
    for (int i=1;i<=n;++i) {
        scanf("%s",s+1);
        int len=std::strlen(s+1);
        for (int j=1;j<=len;++j) sft.extend(s[j]-'a');
        sft.extend(i+26);
        for (int j=last;j<=sft.n;++j) belong[j]=i; last=sft.n+1; endpos[i]=sft.n-1;
    } dfs(1); dfs2(1,0);
    for (int i=1;i<=n;++i) printf("%lld ",ans[i]);
    return 0;
}