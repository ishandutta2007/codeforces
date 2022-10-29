#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

vector<int> g[100010];
int d[100010];
map<pair<int,int>,int> id;
int n,m;
queue<int> q;

int main(){
	int x0,y0,x1,y1;
	scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
	if(x0==x1&&y0==y1){puts("0");return 0;}
	id[mp(x0,y0)]=n++;
	id[mp(x1,y1)]=n++;
	scanf("%d",&m);
	fore(i,0,m){
		int x,a,b;
		scanf("%d%d%d",&x,&a,&b);
		for(int y=a;y<=b;++y){
			if(id.find(mp(x,y))==id.end())id[mp(x,y)]=n++;
		}
	}
	for(map<pair<int,int>,int>::iterator it=id.begin();it!=id.end();++it){
		int x=it->fst.fst,y=it->fst.snd,a=it->snd;
		fore(i,-1,2)fore(j,-1,2){
			if(!i&&!j)continue;
			if(id.find(mp(x+i,y+j))!=id.end())g[a].pb(id[mp(x+i,y+j)]);
		}
	}
	memset(d,-1,sizeof(d));
	d[0]=0;
	q.push(0);
	while(!q.empty()){
		int x=q.front();q.pop();
		fore(i,0,g[x].size()){
			int y=g[x][i];
			if(d[y]<0){
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
	printf("%d\n",d[1]);
	return 0;
}