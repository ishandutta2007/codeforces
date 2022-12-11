#include<cstdio>
#include<vector>
using namespace std;

vector<int>g[500002];
int w;
int a[500001],b[500001];
int ff(int l,int r){
//	printf("??%d %d\n",l,r);
	if(g[r].size()==0){
		if(l==r)return 1;
		if(a[r-1]==-1||a[r-1]==r){
			b[r-1]=--w;
			return ff(l,r-1);
		}
		else return 0;
	}
	for(int i=0;i<g[r].size();i++)
		b[g[r][i]]=--w;
	if(!b[r-1]){
		if(a[r-1]!=-1)return 0;
		b[r-1]=--w;
		g[r].push_back(r-1);
	}
	for(int i=0;i<g[r].size();i++)
		if(!ff(i==0?l:g[r][i-1]+1,g[r][i]))return 0;
	return 1;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d",&n);
		for(int i=0;i<=n+1;i++){
			g[i].clear();
			b[i]=0;
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]!=-1)
				g[a[i]].push_back(i);
		}
		w=n+1;
		if(!ff(1,n+1))
			printf("-1\n");
		else{
			for(int i=1;i<=n;i++)
				printf("%d%c",b[i],i==n?'\n':' ');
		}
	}
}