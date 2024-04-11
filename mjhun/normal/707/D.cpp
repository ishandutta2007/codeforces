#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int nd[100005];
int n,m,nq;
vector<int> g[100005];
vector<int> w[100005];
int tq[100005];
int aq[100005];
int bq[100005];
int rs[100005];
int nn;

int b[1024][1024];
bool inv[1024];  // si b[i] va invertido
int q[1024];  // #1 (en b)
int r;

void dfs(int x){
	int c;
	if(tq[x]==1||tq[x]==2){
		int i=aq[x],j=bq[x],t=2-tq[x];
		c=b[i][j];
		if(!inv[i]){
			if(c!=t){
				b[i][j]=t;
				if(t)q[i]++,r++;
				else q[i]--,r--;
			}
		}
		else {
			if(c==t){
				b[i][j]=1-c;
				if(t)q[i]--,r++;
				else q[i]++,r--;
			}
		}
	}
	else if(tq[x]==3){
		int k=aq[x];
		int s0=q[k],s1=m-q[k];
		if(inv[k])swap(s0,s1);
		inv[k]=!inv[k];
		r+=s1-s0;
	}
	fore(i,0,w[x].size())rs[w[x][i]]=r;
	fore(i,0,g[x].size())dfs(g[x][i]);
	if(tq[x]==1||tq[x]==2){
		int i=aq[x],j=bq[x],t=2-tq[x];
		swap(c,t);
		if(inv[i])c=1-c,t=1-t;
		if(!inv[i]){
			if(c!=t){
				b[i][j]=t;
				if(t)q[i]++,r++;
				else q[i]--,r--;
			}
		}
		else {
			if(c==t){
				b[i][j]=1-c;
				if(t)q[i]--,r++;
				else q[i]++,r--;
			}
		}
	}
	else if(tq[x]==3){
		int k=aq[x];
		int s0=q[k],s1=m-q[k];
		if(inv[k])swap(s0,s1);
		inv[k]=!inv[k];
		r+=s1-s0;
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&nq);
	fore(i,1,nq+1){
		int t;
		scanf("%d",&t);
		if(t==4){
			int x;
			scanf("%d",&x);
			nd[i]=nd[x];
		}
		else {
			nd[i]=i;
			tq[i]=t;
			if(t<=2)scanf("%d%d",aq+i,bq+i),aq[i]--,bq[i]--;
			else scanf("%d",aq+i),aq[i]--;
			g[nd[i-1]].pb(nd[i]);
		}
		w[nd[i]].pb(i);
	}
	dfs(0);
	fore(i,1,nq+1)printf("%d\n",rs[i]);
	return 0;
}