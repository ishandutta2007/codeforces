#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define fst first
#define snd second
#define mp make_pair
#define fore(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define SZ(x) ((int)(x).size())
#define mset(x,t) memset(x,t,sizeof(x))
#define mcpy(x,y) memcpy(x,y,sizeof(x))
using namespace std;
typedef long long ll;

#define MOD 998244353

int uf[2048];
int find(int x){
	if(uf[x]<0)return x;
	return uf[x]=find(uf[x]);
}
void join(int x, int y){
	x=find(x);y=find(y);
	if(x==y)return;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];
	uf[y]=x;
}

char s[1024];int n;

vector<int> g[2048];
int v[2048];

void add(int x, int y){
	x=find(x);y=find(y);
	//printf(" a %d %d\n",x,y);
	g[x].pb(y);g[y].pb(x);
}

bool dfs(int x){
	bool r=true;
	for(int y:g[x]){
		if(v[y]<0){
			v[y]=v[x]^1;
			if(!dfs(y))r=false;
		}
		else if(v[x]==v[y])r=false;
	}
	return r;
}

int p2[2048];

int main(){
	p2[0]=1;
	fore(i,1,2048){
		p2[i]=2*p2[i-1];
		if(p2[i]>=MOD)p2[i]-=MOD;
	}
	scanf("%s",s);n=strlen(s);
	int r=0;
	fore(i,0,n){
		mset(uf,-1);
		fore(j,0,2048)g[j].clear();
		fore(j,0,n)join(n+j,n+n-1-j);
		fore(j,0,i-2)join(j,j+1);
		fore(j,i,n)join(j,n-1-(j-i));
		fore(i,0,n)if(s[i]=='0')join(i,i+n);
		join(i,n);
		if(i)add(i-1,i);
		fore(i,0,n)if(s[i]=='1')add(i,i+n);
		mset(v,-1);
		int q=0;bool can=true;
		fore(i,0,2*n)if(uf[i]<0&&v[i]<0){
			q++;
			v[i]=0;
			if(!dfs(i)){can=false;break;}
		}
		//printf(" %d %d\n",i,-1);
		if(!can)continue;
		//printf(" %d %d\n",i,q);
		r+=p2[q-1];
		if(r>=MOD)r-=MOD;
	}
	printf("%d\n",r);
	return 0;
}