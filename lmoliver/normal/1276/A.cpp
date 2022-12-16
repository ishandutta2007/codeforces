#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=150150;
typedef pair<int,bool> P;
P dp[N][5];
int nxts[N][5];

const map<char,int> tr[]={
	{{'o',1},{'t',3}},
	{{'n',2},{'o',1},{'t',3}},
	{{'e',-1},{'o',1},{'t',3}},
	{{'w',4},{'o',1},{'t',3}},
	{{'o',-1},{'t',3}},
};

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		memset(dp[s.size()],0,sizeof(dp[s.size()]));
		for(int i=s.size()-1;i>=0;i--){
			for(int j=0;j<5;j++){
				P &ans=dp[i][j];
				ans=P(dp[i+1][j].first+1,true);
				map<char,int>::const_iterator nxt=tr[j].find(s[i]);
				int ns=nxt!=tr[j].end()?nxt->second:0;
				nxts[i][j]=ns;
				if(ns!=-1){
					ans=min(ans,P(dp[i+1][ns].first,false));
				}
			}
		}
		cout<<dp[0][0].first<<endl;
		int st=0;
		for(size_t i=0;i<s.size();i++){
			if(dp[i][st].second){
				cout<<(i+1)<<" ";
			}
			else{
				st=nxts[i][st];
			}
		}
		cout<<endl;
	}
	return 0;
}