#include<bits/stdc++.h>
using namespace std;
int const N=33;
int n,pos[N],cnt[N],pre[N][N],pcnt[N][N];
string s,t;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>n;n--;){
		cin>>s>>t,memset(pos,-1,sizeof pos);
		for(int i=0;i<=s.size();i++){
			for(int j=0;j<N;j++)
				pre[i][j]=pos[j],pcnt[i][j]=cnt[j];
			if(i<s.size())
				pos[s[i]-64]=i,cnt[s[i]-64]++;
		}
		int flg=1,cur=s.size();
		for(int i=t.size()-1;i>=0;i--){
			if(~pre[cur][t[i]-64])
				flg&=pcnt[cur][t[i]-64]==cnt[t[i]-64]--,
				cur=pre[cur][t[i]-64];
			else flg=0;
		}
		cout<<(flg?"YES\n":"NO\n");
	}
}