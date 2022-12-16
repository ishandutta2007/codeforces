#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
const int N=2020;
void gg(){
	puts("NO");
	exit(0);
}
int n;
int p[N],c[N];
VI ord[N];
int ans[N];
VI ch[N];
void dfs(int x){
	for(int i=0;i<(int)ch[x].size();i++){
		int c=ch[x][i];
		// cerr<<"c "<<c<<endl;
		dfs(c);
	}
	// cerr<<"x "<<x<<endl;
	if(c[x]<0||c[x]>(int)ord[x].size()){
		gg();
	}
	ord[x].insert(ord[x].begin()+c[x],x);
	for(int j=0;j<(int)ord[x].size();j++){
		ord[p[x]].push_back(ord[x][j]);
	}
}
int main(){
	scanf("%d",&n);
	int rt;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i],&c[i]);
		if(p[i]!=0){
			ch[p[i]].push_back(i);
		}
		else{
			rt=i;
		}
	}
	dfs(rt);
	for(int i=0;i<n;i++){
		ans[ord[0][i]]=i+1;
	}
	puts("YES");
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}