#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

int t[1<<20][32];
int q[1<<20];
int nt;
vector<int> g[300005];
int w[300005];
char s[300005];
int z[300005];
int c[300005];
int r[300005];
int n;

void merge(int t0, int t1){
	fore(i,0,26){
		if(t[t1][i]<0)continue;
		if(t[t0][i]>=0)merge(t[t0][i],t[t1][i]);
		else t[t0][i]=t[t1][i];
	}
	q[t0]=1;
	fore(i,0,26)if(t[t0][i]>=0)q[t0]+=q[t[t0][i]];
}

void dfs(int x, int f){
	z[x]=1;
	int h=-1;
	fore(i,0,g[x].size()){
		int y=g[x][i];
		if(y==f)continue;
		dfs(y,x);
		if(h<0||z[y]>z[h])h=y;
		z[x]+=z[y];
	}
	if(h<0){
		w[x]=nt++;
		t[w[x]][s[x]]=nt++;
		q[nt-1]=1;
		q[w[x]]=2;
	}
	else {
		fore(i,0,g[x].size()){
			int y=g[x][i];
			if(y==f||y==h)continue;
			merge(w[h],w[y]);
		}
		w[x]=nt++;
		t[w[x]][s[x]]=w[h];
		q[w[x]]=q[w[h]]+1;
	}
	r[x]=q[w[x]]-1;
}

int main(){
	memset(t,-1,sizeof(t));
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",c+i);
	scanf("%s",s);fore(i,0,n)s[i]-='a';
	fore(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(0,-1);
	/*
	puts("");
	fore(i,0,n){
		printf("%d %d\n",i+1,r[i]);
	}
	puts("");*/
	int r0=-1,r1=0;
	fore(i,0,n)r0=max(r0,r[i]+c[i]);
	fore(i,0,n)if(r[i]+c[i]==r0)r1++;
	printf("%d\n%d\n",r0,r1);
	return 0;
}