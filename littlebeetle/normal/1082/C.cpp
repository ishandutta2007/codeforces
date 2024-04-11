#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100002;
int n,m,s,r,p[N],i,j,k;
vector<int>v[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d%d",&s,&r);
		v[s].push_back(r);
	}
	for(i=1;i<=m;i++){
		sort(v[i].begin(),v[i].end(),cmp);
		for(k=j=0;j<v[i].size();j++){
			k+=v[i][j];
			if(k<0)break;
			p[j]+=k;
		}
	}
	for(i=0,k=0;i<=n;i++)
		if(p[i]>k)
			k=p[i];
	printf("%d",k);
	return 0;
}