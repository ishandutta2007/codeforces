#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,s[N],base[20],v[20],num,x,vis[N*2];
inline void ins(int x){
	int t=x;
	for(int i=19;i>=0;i--)
		if(x>>i&1){
			if(base[i]){x^=base[i];continue;}
			base[i]=x,v[i]=t,num++;break;
		}
}
void dfs(int t){
	vis[t]=1;
	printf("%d ",t);
	for(int i=0;i<x;i++) if(!vis[t^v[i]]) dfs(t^v[i]); 
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	sort(s+1,s+n+1);
	for(int i=1,j=1;i<=19;i++){
		for(;j<=n&&s[j]<(1<<i);j++) ins(s[j]);
		if(num==i) x=i;
	}
	printf("%d\n",x);
	dfs(0);
	return 0;
}