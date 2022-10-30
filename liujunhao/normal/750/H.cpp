#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<ext/pb_ds/priority_queue.hpp>  
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
#define MAXN 1000
char s[MAXN+10][MAXN+10];
int dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}},fa[(MAXN+2)*(MAXN+2)+10],bl[MAXN+10][MAXN+10],Q;
int n,m;
set<pii>se;
set<int>vis;
vector<pii>a;
inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void read(){
	int i;
	Read(n),Read(m),Read(Q);
	for(i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(i=3;i<=m+1;i++)
		s[0][i]='#';
	for(i=3;i<=n+1;i++)
		s[i][0]='#';
	for(i=0;i<n-1;i++)
		s[i][m+1]='#';
	for(i=0;i<m-1;i++)
		s[n+1][i]='#';
}
inline int Get_id(int x,int y){
	return x*(m+2)+y+1;
}
bool check(vector<pii>&a){
	int i,d;
	vis.clear();
	for(i=(n+2)*(m+2);i;i--)
		fa[i]=i;
	vis.insert(bl[0][3]);
	vis.insert(bl[3][0]);
	for(auto j:a){
		s[j.first][j.second]='#';
		vis.insert(bl[j.first][j.second]);
		for(d=0;d<8;d++){
			int tx=j.first+dir[d][0],ty=j.second+dir[d][1];
			if(s[tx][ty]=='#')
				if(find(bl[tx][ty])!=find(bl[j.first][j.second])){
					fa[fa[bl[tx][ty]]]=fa[bl[j.first][j.second]];
					vis.insert(bl[tx][ty]);
				}
		}
	}
	for(auto j:a)
		s[j.first][j.second]='.';
	for(auto j:vis){
		if(find(j)==find(bl[0][3]))
		for(auto k:vis){
			if(find(k)==find(bl[3][0])){
				int x=j,y=k;
				if(x>y)
					swap(x,y);
				if(se.find(pii(x,y))!=se.end())
					return 0;
			}
		}
	}
	return 1;
}
void dfs(int x,int y){
	int d,tx,ty;
	for(d=0;d<8;d++){
		tx=x+dir[d][0],ty=y+dir[d][1];
		if(tx>=0&&ty>=0&&tx<=n+1&&ty<=m+1&&s[tx][ty]=='#'&&!bl[tx][ty]){
			bl[tx][ty]=bl[x][y];
			dfs(tx,ty);
		}
	}
}
void solve(){
	int i,j,d1,d2,tx,ty,k;
	for(i=0;i<=n+1;i++)
		for(j=0;j<=m+1;j++)
			if(s[i][j]=='#'&&!bl[i][j]){
				bl[i][j]=Get_id(i,j);
				dfs(i,j);
			}
	for(i=0;i<=n+1;i++)
		for(j=0;j<=m+1;j++){
			if(s[i][j]!='#')
				bl[i][j]=Get_id(i,j);
			for(d1=-2;d1<=2;d1++)
				for(d2=-2;d2<=2;d2++){
					tx=i+d1;
					ty=j+d2;
					if(tx>=0&&ty>=0&&tx<=n+1&&ty<=m+1){
						int a=bl[i][j],b=bl[tx][ty];
						if(a>b)
							swap(a,b);
						se.insert(pii(a,b));
					}
				}
		}
	while(Q--){
		Read(k);
		a.clear();
		while(k--){
			Read(i),Read(j);
			a.push_back(pii(i,j));
		}
		if(check(a))
			puts("YES");
		else
			puts("NO");
		fflush(stdout);
	}
}
int main()
{
	read();
	solve();
}