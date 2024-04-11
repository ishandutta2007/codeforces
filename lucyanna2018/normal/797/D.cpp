#include<bits/stdc++.h>
using namespace std;
#define ran 111111
int res,n,val[ran],lef[ran],rig[ran];
bool nr[ran];
set<int> s;
void dfs(int i,int l,int r){
	if(l <= val[i] && val[i] <= r)
		s.insert(val[i]);
	if(lef[i] != -1 && l < val[i])
		dfs(lef[i], l, min(val[i]-1, r));
	if(rig[i] != -1 && r > val[i])
		dfs(rig[i], max(val[i]+1, l), r);
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d%d%d",&val[i],&lef[i],&rig[i]);
		if(lef[i] != -1)nr[lef[i]] = true;
		if(rig[i] != -1)nr[rig[i]] = true;
	}
	res=0;
	for(int i=1; i<=n; i++)
		if(!nr[i]){
			dfs(i,-1,1000000001);
		}
	for(int i=1; i<=n; i++)
		if(!s.count(val[i]))
			res++;
	printf("%d\n",res);
	return 0;
}