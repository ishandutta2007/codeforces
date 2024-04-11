#include <cstdio>
#include <cstring>
#include <vector>
#define ll long long
#define pb push_back
using namespace std;

int n,m;
vector<int> g[100005];
int v[100005];
int s[2];

bool dfs(int k,int c){
	bool r=true;
	v[k]=c;
	s[c]++;
	for(int i=0;r&&i<g[k].size();++i){
		int l=g[k][i];
		if(v[l]==-1){
			r=r&&dfs(l,1-c);
		}
		else if(v[l]==v[k]){
			r=false;
		}
	}
	return r;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int a,b;
		scanf("%d%d",&a,&b);a--;b--;
		g[a].pb(b);g[b].pb(a);
	}
	if(m==0){
		printf("3 %I64d\n",((ll)n)*(n-1)*(n-2)/6);
		return 0;
	}
	bool q=true;
	for(int i=0;q&&i<n;++i){
		q=q&&g[i].size()<=1;
	}
	if(q){
		printf("2 %I64d\n",((ll)m)*(n-2));
		return 0;
	}
	memset(v,-1,sizeof(v));
	ll r=0;q=true;
	for(int i=0;q&&i<n;++i){
		if(v[i]<0){
			s[0]=s[1]=0;
			q=q&&dfs(i,0);
			r+=((ll)s[0])*(s[0]-1)/2;
			r+=((ll)s[1])*(s[1]-1)/2;
		}
	}
	if(q){
		printf("1 %I64d\n",r);
	}
	else {
		puts("0 1");
	}
	return 0;
}