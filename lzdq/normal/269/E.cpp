#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
typedef long long ll;
using namespace std;
typedef pair<int,int> pr;
#define mkp make_pair
const int MAXN=1e5+5,k1=114514,p1=1004535809,k2=1919810,p2=1e9+7;
ll pw1[MAXN*4],pw2[MAXN*4];
int n,m,p[MAXN][4],to[MAXN*4],tp[MAXN*4],ty[MAXN*4];
int cntp;
int cvt(char c){
	if(c=='L') return 1;
	if(c=='R') return 3;
	if(c=='T') return 0;
	if(c=='B') return 2;
	return -1;
}
int des[MAXN*4],c[4][4];
void Quit(){
	puts("No solution");
	exit(0);
}
struct node{
	pr h;
	int u,v;
};
bool operator <(node a,node b){
	return a.h<b.h;
}
bool operator ==(node a,node b){
	return a.h==b.h;
}
int len,s[MAXN*8];
pr hs[MAXN*8];
inline pr geth(int l,int r){
	int h1=(hs[r].first-1ll*hs[l-1].first*pw1[r-l+1]%p1+p1)%p1;
	int h2=(hs[r].second-1ll*hs[l-1].second*pw2[r-l+1]%p2+p2)%p2;
	return mkp(h1,h2);
}
bool Cmp(int a,int b){
	int l=0,r=len;
	while(l<r){
		int mid=l+r+1>>1;
		if(geth(a,a+mid-1)==geth(b,b+mid-1)) l=mid;
		else r=mid-1;
	}
	if(l==len||s[a+l]>s[b+l]) return 0;
	return 1;
}
node Calc(vector<int> &a){
	len=a.size();
	for(int i=1; i<len*2; i++)
		s[i]=tp[a[i%len]];
	hs[0]=mkp(0,0);
	for(int i=1; i<len*2; i++){
		int h1=(1ll*hs[i-1].first*k1+s[i])%p1;
		int h2=(1ll*hs[i-1].second*k2+s[i])%p2;
		hs[i]=mkp(h1,h2);
	}
	int w=1;
	for(int i=2; i<=len; i++)
		if(Cmp(i,w)) w=i;
	vector<int> r1,r2;
	int w1,w2;
	w1=w;
	for(int i=w; i<w+len; i++)
		r1.push_back(tp[a[i%len]]);
	reverse(a.begin(),a.end());
	for(int i=1; i<len*2; i++)
		s[i]=tp[a[i%len]];
	hs[0]=mkp(0,0);
	for(int i=1; i<len*2; i++){
		int h1=(1ll*hs[i-1].first*k1+s[i])%p1;
		int h2=(1ll*hs[i-1].second*k2+s[i])%p2;
		hs[i]=mkp(h1,h2);
	}
	w=1;
	for(int i=2; i<=len; i++)
		if(Cmp(i,w)) w=i;
	w2=w;
	for(int i=w; i<w+len; i++)
		r2.push_back(tp[a[i%len]]);
	int rev=0;
	if(r1<r2){
		reverse(a.begin(),a.end());
		for(int i=1; i<len*2; i++)
			s[i]=tp[a[i%len]];
		w=w1;
	}else w=w2,rev=1;
	pr h(0,0);
	for(int i=0; i<len; i++){
		int h1=(1ll*h.first*k1+s[i+w])%p1;
		int h2=(1ll*h.second*k2+s[i+w])%p2;
		h=mkp(h1,h2);
	}
	//printf("rev %d w %d u %d v %d\n",rev,w,a[w%len],a[(w+1)%len]); puts("");
	return (node){h,a[w%len],a[(w+1)%len]};
}
void Gen(int *ed,multiset<node> &st){
	//puts("Gen");
	static bool vis[MAXN*4];
	memset(vis,0,sizeof(vis));
	vector<int> a;
	for(int i=1; i<=cntp; i++){
		if(vis[i]) continue;
		a.clear();
		int u=i;
		do{
			a.push_back(u);
			vis[u]=1;
			u=ed[u];
			if(u==i) break;
			a.push_back(u);
			vis[u]=1;
			u=p[ty[u]][tp[u]^2];
			//printf("fuck %d %d\n",tp[u],ty[u]);
		}while(u!=i);
		//for(int i=0; i<a.size(); i++) printf("%d %d\n",ty[a[i]],tp[a[i]]); puts("");
		st.insert(Calc(a));
	}
	return ;
}
multiset<node> mt,md;
int ans1[MAXN],ans2[MAXN];
void GetPath(vector<int> &a,int *ed,int s,int f){
	int t=s;
	do{
		a.push_back(s);
		int v1=ed[s],v2=p[ty[s]][tp[s]^2],v;
		if(v1==f) v=v2;
		else v=v1;
		f=s;
		s=v;
	}while(s!=t);
	return ;
}
int main(){
	//freopen("in1.txt","r",stdin);
	scanf("%d%d",&n,&m);
	pw1[0]=1;
	for(int i=1; i<MAXN*4; i++)
		pw1[i]=pw1[i-1]*k1%p1;
	pw2[0]=1;
	for(int i=1; i<MAXN*4; i++)
		pw2[i]=pw2[i-1]*k2%p2;
	for(int i=1; i<=m; i++){
		p[i][0]=++cntp;
		tp[cntp]=0;
		ty[cntp]=i;
		p[i][2]=++cntp;
		tp[cntp]=2;
		ty[cntp]=i;
	}
	for(int i=1; i<=n; i++){
		p[i][1]=++cntp;
		tp[cntp]=1;
		ty[cntp]=i;
		p[i][3]=++cntp;
		tp[cntp]=3;
		ty[cntp]=i;
	}
	for(int i=1; i<=n+m; i++){
		static char a[2],b[2];
		int x,y;
		scanf("%s%s%d%d",a,b,&x,&y);
		int cx=cvt(a[0]),cy=cvt(b[0]);
		c[cx][cy]++;
		c[cy][cx]++;
		x=p[x][cx];
		y=p[y][cy];
		to[x]=y;
		to[y]=x;
	}
	if(c[0][2]&&c[1][3]) Quit();
	for(int i=1; i<=c[0][1]; i++){
		int u=p[i][0],v=p[i][1];
		des[u]=v;
		des[v]=u;
	}
	for(int i=1; i<=c[0][3]; i++){
		int u=p[m-i+1][0],v=p[i][3];
		des[u]=v;
		des[v]=u;
	}
	for(int i=1; i<=c[2][1]; i++){
		int u=p[i][2],v=p[n-i+1][1];
		des[u]=v;
		des[v]=u;
	}
	for(int i=1; i<=c[2][3]; i++){
		int u=p[m-i+1][2],v=p[n-i+1][3];
		des[u]=v;
		des[v]=u;
	}
	for(int i=1; i<=c[0][2]; i++){
		int u=p[i+c[0][1]][0],v=p[i+c[2][1]][2];
		des[u]=v;
		des[v]=u;
	}
	for(int i=1; i<=c[1][3]; i++){
		int u=p[i+c[0][1]][1],v=p[i+c[0][3]][3];
		des[u]=v;
		des[v]=u;
	}
	Gen(to,mt);
	//for(int i=1; i<=cntp; i++) printf("%d %d des %d %d\n",ty[i],tp[i],ty[des[i]],tp[des[i]]);
	Gen(des,md);
	//printf("mt %lu md %lu\n",mt.size(),md.size());
	if(mt.size()!=md.size()) Quit();
	for(node i:mt){
		auto it=md.find(i);
		if(it==md.end()) Quit();
		vector<int> p1,p2;
		GetPath(p1,to,i.u,i.v);
		GetPath(p2,des,it->u,it->v);
		//printf("p1 %lu p2 %lu\n",p1.size(),p2.size());
		for(int i=0; i<p1.size(); i++){
			int x=p1[i],y=p2[i];
			if(tp[x]&1) ans1[ty[y]]=ty[x];
			else ans2[ty[y]]=ty[x];
		}
		md.erase(it);
	}
	for(int i=1; i<=n; i++)
		printf("%d ",ans1[i]);
	puts("");
	for(int i=1; i<=m; i++)
		printf("%d ",ans2[i]);
	puts("");
	return 0;
}