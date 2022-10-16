#include<bits/stdc++.h>
#define SIZE [s[1].size()-1][s[2].size()-1][s[3].size()-1]
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;} 
int n,q;
string t,s[4];
int dp[252][252][252];
int suf[26];
int nxt[100005][26];
void init(){
	memset(suf,inf,sizeof suf);
	for(int i=t.size()-1;i>=0;i--){
		for(int j=0;j<26;j++)nxt[i][j]=suf[j];
		suf[t[i]-'a']=i;
	}
}
inline void upd(int &x,int y){x=x<y?x:y;}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q>>t;
	t=" "+t;s[1]=" ";s[2]=" ";s[3]=" ";
	init();
	memset(dp,inf,sizeof dp);
	dp[0][0][0]=0;
	while(q--){
		char op;int p;char add;
		cin>>op;
		if(op=='+'){
			cin>>p>>add;
			s[p].push_back(add);
			if(p==1){
				for(int i=0;i<=250;i++)
					for(int j=0;j<=250;j++)
						if(dp[s[p].size()-2][i][j]!=inf)
							upd(dp[s[p].size()-1][i][j],nxt[dp[s[p].size()-2][i][j]][s[p].back()-'a']);
				for(int i=0;i<s[2].size();i++)
					for(int j=0;j<s[3].size();j++)
						if(dp[s[p].size()-1][i][j]!=inf){
							if(i+1<s[2].size())
								upd(dp[s[p].size()-1][i+1][j],nxt[dp[s[p].size()-1][i][j]][s[2][i+1]-'a']);
							if(j+1<s[3].size())
								upd(dp[s[p].size()-1][i][j+1],nxt[dp[s[p].size()-1][i][j]][s[3][j+1]-'a']);
						}			
			}
			else if(p==2){
				for(int i=0;i<=250;i++)
					for(int j=0;j<=250;j++)
						if(dp[i][s[p].size()-2][j]!=inf)
							upd(dp[i][s[p].size()-1][j],nxt[dp[i][s[p].size()-2][j]][s[p].back()-'a']);
				for(int i=0;i<s[1].size();i++)
					for(int j=0;j<s[3].size();j++)
						if(dp[i][s[p].size()-1][j]!=inf){
							if(i+1<s[1].size())
								upd(dp[i+1][s[p].size()-1][j],nxt[dp[i][s[p].size()-1][j]][s[1][i+1]-'a']);
							if(j+1<s[3].size())
								upd(dp[i][s[p].size()-1][j+1],nxt[dp[i][s[p].size()-1][j]][s[3][j+1]-'a']);
						}
			}else{
				for(int i=0;i<=250;i++)
					for(int j=0;j<=250;j++)
						if(dp[i][j][s[p].size()-2]!=inf)
							upd(dp[i][j][s[p].size()-1],nxt[dp[i][j][s[p].size()-2]][s[p].back()-'a']);
				for(int i=0;i<s[1].size();i++)
					for(int j=0;j<s[2].size();j++)
						if(dp[i][j][s[p].size()-1]!=inf){
							if(i+1<s[1].size())
								upd(dp[i+1][j][s[p].size()-1],nxt[dp[i][j][s[p].size()-1]][s[1][i+1]-'a']);
							if(j+1<s[2].size())
								upd(dp[i][j+1][s[p].size()-1],nxt[dp[i][j][s[p].size()-1]][s[2][j+1]-'a']);
						}
			}
		}else{
			cin>>p;
			s[p].pop_back();
			if(p==1){
				for(int i=0;i<=250;i++)
					for(int j=0;j<=250;j++)
						dp[s[p].size()][i][j]=inf;
			}else if(p==2){
				for(int i=0;i<=250;i++)
					for(int j=0;j<=250;j++)
						dp[i][s[p].size()][j]=inf;
			}else{
				for(int i=0;i<=250;i++)
					for(int j=0;j<=250;j++)
						dp[i][j][s[p].size()]=inf;
			}
		}
		cerr<<dp SIZE<<endl;
		if(dp SIZE<=n)puts("YES");
		else puts("NO");
	}
	return 0;
}