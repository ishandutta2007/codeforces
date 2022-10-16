#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

string s,t;
int l[N],r[N],fl[N],dp[N],sg[N],bc[N],fa[N],cnt;
char nx[N];
int n,m;

void set1(int k){
	while(k!=0&&!fl[k])fl[k]=1,k=fa[k],m--;
}

void dfs(int k){
	if(!k)return ;
	dp[k]=dp[fa[k]]+1;
	fa[l[k]]=k,dfs(l[k]);
	bc[cnt]=k,sg[k]=cnt++;
	t+=s[k];
	fa[r[k]]=k,dfs(r[k]);
}

void df5(int k,int fs){
	if(!k)return ;
	df5(l[k],fs);
	if(nx[sg[k]]>t[sg[k]]&&dp[k]-fs<=m)
		set1(k); 
	if(fl[k])df5(r[k],dp[k]);
}

main(){
	cin>>n>>m;cin>>s;s='0'+s;
	for(int i=1;i<=n;i++)cin>>l[i]>>r[i];
	dfs(1);
	nx[t.size()-1]=' ';
	for(int i=((int)t.size())-2;i>=0;i--){
		if(t[i]==t[i+1])nx[i]=nx[i+1];
		else nx[i]=t[i+1];	
	}
	df5(1,0);
	for(int i=0;i<n;i++){
		cout<<t[i];
		if(fl[bc[i]])cout<<t[i];
	}
}