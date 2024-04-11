#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair

using namespace std;

inline int read(){
	int i;
	scanf("%d",&i);
	return i;
}

typedef pair<int,int> pii;

int m[2500][2500],nx[2502],pr[2502];
pii e[2500*2500/2];
bool used[2500];

int main(){
	int n=read();
	REP(i,n)REP(j,n)
		m[i][j]=read();
	REP(i,n)if(m[i][i]){
		printf("NOT MAGIC\n");
		return 0;
	}
	REP(i,n)REP(j,n)if(m[i][j]!=m[j][i]){
		printf("NOT MAGIC\n");
		return 0;
	}
	int s=0;
	REP(i,n)FOR(j,i+1,n)
		e[s++]=MP(m[i][j],(i<<12)|j);
	sort(e,e+s);
	nx[n+1]=0;
	REP(i,n)
		nx[i]=i+1;
	pr[0]=n+1;
	FOR(i,1,n+1)
		pr[i]=i-1;
	REP(_,s){
		int p=e[_].second>>12,q=e[_].second&((1<<12)-1);
		if(used[p]||used[q])
			continue;
		int i=nx[n+1];
		while(i!=n){
			if(i!=p&&i!=q&&m[p][i]!=m[q][i]){
				printf("NOT MAGIC\n");
				return 0;
			}
			i=nx[i];
		}
		used[p]=true;
		int u=pr[p],v=nx[p];
		nx[u]=v;
		pr[v]=u;
	}
	printf("MAGIC\n");
}