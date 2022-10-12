#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define ran 1000010
int n,sz[ran];
bool f[ran];
pair<int,int> a[ran];
vector<int> e[ran];
int ace[ran];int ancestor(int x){return x-ace[x]?ace[x]=ancestor(ace[x]):x;}
void doit(int x,int val,long long int&res){
	f[x] = true;
	long long int w = 1;
	for(vector<int>::iterator it = e[x].begin(); it != e[x].end(); it++){
		int y = *it;
		if(!f[y])continue;
		int z = ancestor(y);
		w += (long long int)sz[x] * sz[z];
		sz[x] += sz[z];
		ace[z] = x;
	}
	res += w * val;
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i].first);
		a[i].second = i;
	}
	sort(a+1,a+n+1);
	for(int i=1; i<n; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	
	long long int res1=0,res2=0;
	for(int i=1; i<=n; i++)sz[i] = 1, f[i] = false, ace[i] = i;
	for(int i=1; i<=n; i++)doit(a[i].second,a[i].first,res1);

	for(int i=1; i<=n; i++)sz[i] = 1, f[i] = false, ace[i] = i;
	for(int i=n; i>=1; i--)doit(a[i].second,a[i].first,res2);

	printf("%I64d\n",res1-res2);
	return 0;
}