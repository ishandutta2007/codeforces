#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
typedef pair<int,int> pii;
const int N=2005;

int n,len,tot,cnt,x,y,cur;
bool a[N][N],g[N][N];
pii st[N*N];
bool vis[N][N];
double lee[N*N];
queue<pii> q;

bool dfs(int s,int t){
	q.push(pii(s,t));
	vis[s][t]=1;
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		int cnt=0,tot=0;
		rep(dx,-3,3) rep(dy,-3,3){
			int u=x+dx,v=y+dy;
			if(u>0 && u<=n && v>0 && v<=n && !vis[u][v]){
				++tot;
				if(a[u][v])
					++cnt;
			}
		}
		if(x==s && y==t && cnt<tot*0.5) return 0;
		st[++len]=pii(x,y);
		g[x][y]=1;
		if(cnt<tot*0.5){
			continue;
		}
		rep(dx,-3,3) rep(dy,-3,3){
			int u=x+dx,v=y+dy;
			if(u>0 && u<=n && v>0 && v<=n && !vis[u][v])
			if(a[u][v]){
				q.push(pii(u,v));
				vis[u][v]=1;
			}
		}
	}
	return 1;
}

inline double sqr(double x){return x*x;}

inline double dist(int x1,int x2,int y1,int y2){
	return sqrt(sqr(x1-x2)+sqr(y1-y2));
}

double calc(int x,int y){
	double ans=0;
	rep(i,1,len) ans+=dist(x,st[i].first,y,st[i].second);
	return ans;
}


inline bool cmp(const pii &a,const pii &b){
	return dist(x,a.first,y,a.second)>dist(x,b.first,y,b.second);
}

int main(){
	scanf("%d",&n);
	rep(i,1,n) rep(j,1,n){
		char ch=getchar();
		while(ch!='1' && ch!='0') ch=getchar();
		a[i][j]=ch=='1';
	}
	int cnt=0;
	rep(i,1,n) rep(j,1,n)
		if(!vis[i][j] && a[i][j]){
			len=0;
			if(dfs(i,j)){
				if(len<120) continue;
				++tot;
				//printf("%d %d\n",i,j);
				//rep(l,1,len) printf("%d %d\n",st[l].first,st[l].second);
				x=i,y=j;
				double mx=0;
				rep(l,1,len){
					double dis=dist(st[l].first,x,st[l].second,y);
					if(dis>mx){
						mx=dis;
					}
				}
				int z=sqr(mx/2)*3.14;
				if((double)len/z>0.73) ++cnt;
				//printf("%.3lf\n",(double)len/z);
			}
		}
	//return 0;
	/*
	rep(i,1,n){
		rep(j,1,n){
			//if(ff[i][j]) {putchar('?');putchar(' ');continue;}
			//if(f[i][j]) {putchar('!');putchar(' ');continue;}
			if(g[i][j]) putchar('1');
			else putchar('0');
			putchar(' ');
		}
		puts("");
	}
	*/
	printf("%d %d\n",cnt,tot-cnt);
	//printf("%d\n",tot);
}