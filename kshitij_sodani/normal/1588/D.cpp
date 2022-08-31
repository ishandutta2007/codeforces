//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int dp[1<<10][52];
pair<int,int> ba[1<<10][52];
int re[10][110][52];
vector<int> it[11];
vector<int> tt[11][52];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<(1<<n);i++){
			for(int j=0;j<52;j++){
				dp[i][j]=-1;
				ba[i][j]={-1,-1};
			}
		}
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			it[i].clear();
			for(int j=0;j<52;j++){
				re[i][s.size()][j]=-1;
				tt[i][j].clear();
			}
			for(int j=0;j<s.size();j++){
				int x=s[j]-'a';
				if(x>=0 and x<26){
					it[i].pb(x);
				}
				else{
					it[i].pb(26+s[j]-'A');
				}
				tt[i][it[i][j]].pb(j);
			}
			for(int j=s.size()-1;j>=0;j--){
				for(int jj=0;jj<52;jj++){
					re[i][j][jj]=re[i][j+1][jj];
				}
				if(j+1<s.size()){
					re[i][j][it[i][j+1]]=j+1;
				}
			}
		}
		for(int i=it[0].size()-1;i>=0;i--){
			int cur=it[0][i];
			//cout<<cur<<":"<<endl;
			for(int j=0;j<(1<<n);j++){
				int st=1;
				vector<int> ind;

				for(int k=0;k<n;k++){
					if(k>0){
						/*if(i==2 and j==0){
							cout<<tt[k][cur].size()<<endl;
						}*/
						if(tt[k][cur].size()==0){
							st=0;
							break;
						}
						if(tt[k][cur].size()==1){
							if((1<<k)&j){
								st=0;
								break;
							}
						}
					}
					else{
						if((i!=tt[0][cur][(j%2)])){
							st=0;
							break;
						}
					}
				}
				/*if(cur==15 and j==0){
					cout<<st<<":"<<endl;
				}*/
				if(st==0){
				//	dp[i][j]=-1;
					continue;
				}

				//cout<<j<<":"<<i<<endl;
				dp[j][cur]=1;
				ba[j][cur]={-1,-1};
				for(int k=0;k<n;k++){
					if((1<<k)&j){
						ind.pb(tt[k][cur][1]);
					}
					else{
						ind.pb(tt[k][cur][0]);
					}
				}
				for(int k=0;k<52;k++){
					//int ma=-1;
					int su=0;
					int stt=1;
					for(int kk=0;kk<n;kk++){
						int x=re[kk][ind[kk]][k];
						/*if(j==0 and cur==2 and k==4){
							cout<<x<<":"<<endl;
						}*/
						if(x==-1){
							stt=0;
							break;
						}
						if(tt[kk][k][0]==x){
							continue;
						}
						else{
							su+=(1<<kk);
						}
					}
				/*	if(j==0 and cur==2 and k==14){
						cout<<stt<<endl;
						cout<<su<<endl;
						cout<<dp[su][k]<<endl;
					}
*/
					if(stt==0){
						continue;
					}
					
					if(dp[j][cur]<dp[su][k]+1){
						dp[j][cur]=dp[su][k]+1;
						ba[j][cur]={su,k};
					}
				}
			}
		}
		pair<int,pair<int,int>> ma={0,{-1,-1}};
		for(int i=0;i<(1<<n);i++){
			for(int j=0;j<52;j++){
				ma=max(ma,{dp[i][j],{i,j}});
			}
		}
		cout<<ma.a<<endl;
		pair<int,int> cot=ma.b;
		string s="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

		for(int i=0;i<ma.a;i++){
			cout<<s[cot.b];
			cot=ba[cot.a][cot.b];
		}
		cout<<endl;
		//cout<<ma.a<<":"<<ma.b.a<<":"<<ma.b.b<<endl;


		//cout<<dp[0][4]<<endl;
	}





 
	return 0;
}