#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
#define MAXM 100000
#define MAXN 100000
using namespace std;
typedef long long LL;
typedef pair<int,int>pii;
vector<pii>pos[MAXM+10];
int n,m,len[MAXN+10];
map<int,int>vis[41];
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
void exgcd(LL a,LL b,LL &x,LL &y){
	if(!b){
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
//ax+by=d
//bx'+a%by'=d
//bx'+(a-a*b/b)y'=d
//ay'+b(x'-a/b*y')=d
LL merge(LL a,LL b,LL c,LL d){
	LL g=__gcd(b,d),x,y;
	exgcd(b/g,d/g,x,y);
	if((c-a)%g)
		return -1;
	x=(c-a)/g*x%(d/g);
	if(x<0)
		x+=d/g;  //it must be non-negative,because I returned a -1 before.
	return b*x+a;
}
/*x=a%b=c%d
x=bp+a=dq+c
bp-dq=c-a
b/g*p-d/g*q=(c-a)/g
p=(c-a)*g*invbg -d*q/g
x=bp+a=b*(c-a)/g*invb+a
*/
void read(){
	Read(n),Read(m);
	int i,j,x;
	for(i=1;i<=n;i++){
		Read(len[i]);
		for(j=0;j<len[i];j++){
			Read(x);
			pos[x].push_back(pii(i,j));
		}
	}
}
void init(){
	int i;
	for(i=1;i<=40;i++){
		vis[i].clear();
	}
}
void add(int x,int y){
	vis[x][y]++;
}
void del(int x,int y){
	if(!--vis[x][y])
		vis[x].erase(y);
}
bool check(){
	int i;
	LL x=0,y=1,nx;
	for(i=1;i<=40;i++){
		if(vis[i].size()>1)
			return 0;
		if(vis[i].size()){
			nx=merge(x,y,vis[i].begin()->first,i);
			if(nx==-1)
				return 0;
			x=nx;
			y=y*i/__gcd(y,1ll*i);
		}
	}
	return 1;
}
void solve(){
	int i,ans;
	vector<pii>::iterator l,r;
	for(i=1;i<=m;i++){
		init();
		ans=0;
		for(r=pos[i].begin();r<pos[i].end();r++){
			if(r==pos[i].begin()||r->first!=(r-1)->first+1){
				init();
				l=r;
			}
			add(len[r->first],r->second);
			while(!check()){
				del(len[l->first],l->second);
				l++;
			}
			ans=max(ans,r-l+1);
		}
		printf("%d\n",ans);
	}
}
int main()
{
	read();
	solve();
}