#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 2000
#define MAXQ 1000000
long long cq,q,c[MAXN+10][MAXN+10],cg[MAXN+10][MAXN+10],pos[MAXN+10],n,m,k,bl[MAXN+10][MAXN+10][3],cnt[MAXN+10];
template<class T>
bool Read(T &x){
	char c;
	bool f=0;
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
			return 1;
		}
	}
	return 0;
}
inline int lowbit(long long x){
	return x&-x;
}
inline void update(long long *c,int x,long long d){
	while(x<=m){
		c[x]+=d;
		x+=lowbit(x);
	}
}
inline void update(int x,int y,long long d){
	while(x<=n){
		update(c[x],y,d);
		x+=lowbit(x);
	}
}
inline long long get_sum(long long *c,int x){
	long long ret=0;
	while(x){
		ret+=c[x];
		x^=lowbit(x);
	}
	return ret;
}
inline long long get_sum(int x,int y){
	long long ret=0;
	while(x){
		ret+=get_sum(c[x],y);
		x^=lowbit(x);
	}
	return ret;
}
struct Query{
	int p,x1,x2,y1,y2;
}Q[MAXQ+10];
void read(){
	Read(n),Read(m),Read(k);
	int i,j;
	for(i=1;i<=k;i++){
		Read(cnt[i]);
		for(j=1;j<=cnt[i];j++)
			Read(bl[i][j][0]),Read(bl[i][j][1]),Read(bl[i][j][2]);
	}
	Read(q);
	char s[20];
	for(i=1;i<=q;i++){
		scanf("%s",s);
		if(*s=='S'){
			Q[i].p=1;
			Read(Q[i].x1);
		}
		else{
			Q[i].p=2;
			Read(Q[i].x1),Read(Q[i].y1),Read(Q[i].x2),Read(Q[i].y2);
			pos[++cq]=i;
		}
	}
}
bool vis[MAXN+10];
void solve(){
	int i,j;
	for(i=1;i<=k;i++){
		for(j=1;j<=cnt[i];j++)
			update(bl[i][j][0],bl[i][j][1],bl[i][j][2]);
		for(j=1;j<=cq;j++)
			cg[j][i]=get_sum(Q[pos[j]].x2,Q[pos[j]].y2)-get_sum(Q[pos[j]].x2,Q[pos[j]].y1-1)-get_sum(Q[pos[j]].x1-1,Q[pos[j]].y2)+get_sum(Q[pos[j]].x1-1,Q[pos[j]].y1-1);
		for(j=1;j<=cnt[i];j++)
			update(bl[i][j][0],bl[i][j][1],-bl[i][j][2]);
	}
	int cc=0;
	long long ans=0;
	for(i=1;i<=q;i++){
		if(Q[i].p==1)
			vis[Q[i].x1]^=1;
		else{
			ans=0;
			cc++;
			for(j=1;j<=k;j++)
				if(!vis[j])
					ans+=cg[cc][j];
			printf("%I64d\n",ans);
		}
	}
}
int main()
{
	read();
	solve();
}