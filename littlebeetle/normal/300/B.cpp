#include<cstdio>
#include<vector>
using namespace std;
const int N=100002;
int n,m,i,j,k,a,b,fa[N],sz[N],sz2,sz1;
int p(int x){
	return x==fa[x]?x:fa[x]=p(fa[x]);
}
vector<int>v[N];
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		fa[i]=i;
		sz[i]++;
	}
	while(m--){
		scanf("%d%d",&a,&b);
		a=p(a);b=p(b);
		if(a!=b){
			sz[b]+=sz[a];
			fa[a]=b;
			sz[a]=0;
		}
	}
	for(i=1;i<=n;i++){
		if(sz[i]>3){
			printf("-1");
			return 0;
		}
		if(sz[i]==2)
			sz2++;
		if(sz[i]==1)
			sz1++;
		v[p(i)].push_back(i);
	}
	if(sz2>sz1){
		printf("-1");
		return 0;
	}
	for(i=1,j=1;i<=n;i++){
		if(v[i].size()==2){
			while(v[j].size()!=1)
				j++;
			v[i].push_back(v[j][0]);
			v[j].pop_back();
		}
		if(v[i].size()==3){
		printf("%d %d %d\n",v[i][0],v[i][1],v[i][2]);
		v[i].pop_back();
		v[i].pop_back();
		v[i].pop_back();
		}
	}
	for(i=1,j=1;i<=n;i++){
		if(v[i].size()==1){
			while(v[j].size()!=1||j==i)
				j++;
			v[i].push_back(v[j][0]);
			v[j].pop_back();
			while(v[j].size()!=1||j==i)
				j++;
			v[i].push_back(v[j][0]);
			v[j].pop_back();			
		}
		if(v[i].size()==3)
		printf("%d %d %d\n",v[i][0],v[i][1],v[i][2]);
	}	
	//while(1);
}