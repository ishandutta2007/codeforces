#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std;
typedef long long LL;
typedef pair<int,int>pii;
typedef unsigned uint;
typedef unsigned long long uLL;
const double pi=acos(-1);
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
//
#define MAXN 30
#define MAXLEN 100000
#define p1 67
#define p2 91
#define MOD 998244353
queue<int>q;
typedef pair<uint,uint>puu;
puu h[MAXLEN+10],hash_pow[MAXLEN+10];
char s[MAXLEN+10];
int bg[MAXN+10],n,in[MAXLEN+10],ans;
inline puu Get_hash(int l,int r){
	return puu(((h[r].first-h[l-1].first*1ll*hash_pow[r-l+1].first)%MOD+MOD)%MOD,h[r].second-h[l-1].second*hash_pow[r-l+1].second);
}
struct node{
	int v;
	node *next;
}*adj[MAXLEN+10],edge[MAXLEN*30+10],*ecnt=edge;
inline void addedge(int u,int v){
	node *p=++ecnt;
	p->v=v;
	p->next=adj[u];
	adj[u]=p;
	in[v]++;
}
void read(){
	Read(n);
	int i;
	bg[1]=1;
	for(i=1;i<=n;i++){
		scanf("%s",s+bg[i]);
		bg[i+1]=bg[i]+strlen(s+bg[i]);
	}
	*hash_pow=puu(1,1);
	for(i=1;i<bg[n+1];i++){
		h[i]=puu((h[i-1].first*1ll*p1+s[i]-'a'+1)%MOD,h[i-1].second*p2+s[i]-'a'+1);
		hash_pow[i]=puu(hash_pow[i-1].first*1ll*p1%MOD,hash_pow[i-1].second*p2);
	}
}
bool check(int l,int r){
	int i,j,k,cnt=0;
	for(i=bg[l];i<=bg[r+1];i++){
		adj[i]=0;
		in[i]=0;
	}
	ecnt=edge;
	for(i=l;i<=r;i++){
		addedge(bg[r+1],bg[i]);
		for(k=l;k<=r;k++){
			for(j=bg[i];j<bg[i+1];j++){
				if(j==bg[i]&&bg[i+1]-bg[i]==bg[k+1]-bg[k])
					continue;
				if(bg[i+1]-j==bg[k+1]-bg[k]){
					if(Get_hash(j,bg[i+1]-1)==Get_hash(bg[k],bg[k+1]-1))
						addedge(j,bg[r+1]);
				}
				else if(bg[i+1]-j<bg[k+1]-bg[k]){
					if(Get_hash(j,bg[i+1]-1)==Get_hash(bg[k],bg[k]+bg[i+1]-j-1))
						addedge(j,bg[k]+bg[i+1]-j);
				}
				else if(Get_hash(j,j+bg[k+1]-bg[k]-1)==Get_hash(bg[k],bg[k+1]-1))
						addedge(j,j+bg[k+1]-bg[k]);
			}
		}
	}
	for(i=bg[l];i<=bg[r+1];i++)
		if(!in[i])
			q.push(i);
	while(!q.empty()){
		cnt++;
		i=q.front();
		q.pop();
		for(node *p=adj[i];p;p=p->next)
			if(!--in[p->v])
				q.push(p->v);
	}
	return cnt==bg[r+1]-bg[l]+1;
}
void solve(){
	int i,j=1;
	for(i=1;i<=n;i++){
		if(j<i)
			j=i;
		while(j<=n&&check(i,j))
			j++;
		ans+=j-i;
	}
}
int main()
{
	read();
	solve();
	printf("%d\n",ans);
}