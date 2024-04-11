#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define infll 1000000000000000000ll
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
using namespace std;

int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
ll readll(){
	ll x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
/*
int tot,fa[N],fst[N],pnt[N<<1],nxt[N<<1];
void add(int x,int y){
	pnt[++tot]=y; nxt[tot]=fst[x]; fst[x]=tot;
}
void dfs(int x){
	int i,y;
	for (i=fst[x]; i; i=nxt[i]){
		y=pnt[i];
		if (y!=fa[x]){
			fa[y]=x; dfs(y);
		}
	}
}
*/
char s[100009];
int main(){
	scanf("%s",s+1);
	int i,n=strlen(s+1);
	int tmp=0,tt=1;
	for (i=1; i<=n; i++) if (s[i]=='0'){
		tmp++;
		if (tmp>4) tmp=1; printf("1 %d\n",tmp);
	} else{
		if (tt>4) tt=1;
		printf("4 %d\n",tt);
		tt+=2;
	}
	return 0;
}