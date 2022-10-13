#include<stdio.h>
#include<vector>
#include<map>
using namespace std;
#define ran 111111
int n,mx,lv;
int a[ran],dep[ran];
vector<int> e[ran];
void dfs(int x){
	if(dep[x] > mx)mx = dep[x];
	for(vector<int>::iterator it = e[x].begin(); it!=e[x].end(); it++){
		int y = *it;
		dep[y] = dep[x] + 1;
		dfs(y);
	}
}
int u[ran],lu;
map<int,int> v;
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for(int i=2; i<=n; i++){
		int x;
		scanf("%d",&x);
		e[x].push_back(i);
	}
	dep[1] = 0;
	dfs(1);
	for(int i=1; i<=n; i++)
		if((mx-dep[i])%2==0)
			u[lu++] = a[i];
		else{
			v[a[i]]++;
			lv++;
		}
	int sg = 0;
	for(int i=0; i<lu; i++)
		sg ^= u[i];
	long long int res = 0;
	if(sg == 0){
		res += lu * (lu - 1LL)/2;
		res += lv * (lv - 1LL)/2;
	}
	for(int i=0; i<lu; i++){
		int w = sg ^ u[i];
		if(v.count(w))
			res += v[w];
	}
	printf("%I64d\n",res);
	return 0;
}