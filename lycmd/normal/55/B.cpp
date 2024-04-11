#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[4],ans=LLONG_MAX;
string s;
int calc(int x,int y,int op){
	return op=='+'?x+y:x*y;
}
void dfs(int x){
	if(x>2){
		for(int i=0;i<4;i++)
			if(~a[i])ans=min(ans,a[i]);
		return;
	}
	for(int i=0;i<4;i++)
		for(int j=i+1;j<4;j++)
			if(~a[i]&&~a[j]){
				int l=a[i],r=a[j];
				a[i]=calc(l,r,s[x]),a[j]=-1;
				dfs(x+1);
				a[i]=l,a[j]=r;
			}
}
signed main(){
	for(int i=0;i<4;i++)cin>>a[i];
	s.resize(3);
	for(auto&i:s)cin>>i;
	dfs(0);
	cout<<ans<<"\n";
}