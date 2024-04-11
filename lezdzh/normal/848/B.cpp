#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int a[100001],b[100001],c[100001],d[100001];
vector<int>x[200001],y[200001];
int ans[100001];
bool cm(int u,int v){return b[u]<b[v];}
int main(){
	int n,w,h;
	scanf("%d%d%d",&n,&w,&h);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		if(a[i]==1)
			x[c[i]-b[i]+100000].push_back(i);
		else y[c[i]-b[i]+100000].push_back(i);
	}
	for(int i=200000;i;i--){
		d[0]=0;
		sort(x[i].begin(),x[i].end(),cm);
		sort(y[i].begin(),y[i].end(),cm);
		for(int j=0;j<x[i].size();j++)
			d[++d[0]]=x[i][j];
		for(int j=y[i].size()-1;j>=0;j--)
			d[++d[0]]=y[i][j];
		d[0]=0;
		for(int j=y[i].size()-1;j>=0;j--)
			ans[y[i][j]]=d[++d[0]];
		for(int j=0;j<x[i].size();j++)
			ans[x[i][j]]=d[++d[0]];
	}
	for(int i=1;i<=n;i++)
		if(a[ans[i]]==1)
			printf("%d %d\n",b[ans[i]],h);
		else printf("%d %d\n",w,b[ans[i]]);
}