#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T;
int sum[maxn],vis[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		cin>>s,n=s.size();
		int lft=n/2,rgt=n/2;
		for(int i=0;i<n;i++){
			if(s[i]=='(')
				lft--;
			if(s[i]==')')
				rgt--;
		}
		int S=0,T=1e9,ans=1;
		for(int i=0;i<n;i++){
			if(s[i]=='?'){
				if(lft)
					lft--,vis[i]=1,s[i]='(',S=max(S,i);
				else vis[i]=2,s[i]=')',T=min(T,i);
			}
			sum[i+1]=sum[i]+(s[i]=='('? 1:-1);
			if(vis[i])
				s[i]='?';
		}
		if(S>0&&T<1e9){
			int flg=1;
			for(int i=S;i<T;i++)
				flg&=sum[i+1]>=2;
			if(flg)
				ans=0;
		}
		puts(ans==0? "NO":"YES");
		for(int i=0;i<=n;i++)
			sum[i]=vis[i]=0;
	}
	return 0;
}