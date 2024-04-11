#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
const llo mod=998244353;

llo n;
llo pre[20][1001];
llo dp[18][1<<17][2];
string s;
llo pre2[1001];
llo ans2=0;
void solve(llo i,llo jj){
	pair<llo,llo> cur={i,jj};
	llo co=0;
	llo su=0;
	while(cur.a>=0 and cur.b<n){

		if(cur.a==cur.b){
			if(s[cur.a]=='?'){
				co++;
			}
		}
		else{
			if(s[cur.a]=='?' and s[cur.b]=='?'){
				co++;
			}
			else if(s[cur.a]=='?'){
				if((su&(1<<(s[cur.b]-'a')))){

				}
				else{
					su+=(1<<(s[cur.b]-'a'));
				}
				
			}
			else if(s[cur.b]=='?'){
				if((su&(1<<(s[cur.a]-'a')))){

				}
				else{
					su+=(1<<(s[cur.a]-'a'));
				}
			}
			else{
				if(s[cur.a]!=s[cur.b]){
					/*if(cur.a==1 and cur.b==2){
						cout<<22<<endl;
					}*/
					break;
				}
			}
		}
		for(llo j=1;j<=17;j++){
			dp[j][su][0]+=pre[j][co+(pre2[cur.a]+pre2[n]-pre2[cur.b+1])];
			if(dp[j][su][0]>=mod){
				dp[j][su][0]-=mod;
			}
		}
		//if(co>0){
			//cout<<cur.a<<":"<<cur.b<<":"<<su<<":"<<co<<endl;
	//	}
		cur.a--;
		cur.b++;

	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	
	cin>>s;
	pre2[0]=0;
	for(int i=1;i<=s.size();i++){
		pre2[i]=pre2[i-1];
		if(s[i-1]=='?'){
			pre2[i]+=1;
		}
	}
	for(llo j=0;j<20;j++){
		pre[j][0]=1;
		for(llo i=1;i<=1000;i++){
			pre[j][i]=(pre[j][i-1]*j)%mod;
		}
	}
	for(llo i=0;i<n;i++){
		solve(i,i);
		if(i<n-1){
			solve(i,i+1);
		}
	}
	for(llo jj=1;jj<=17;jj++){
		for(llo j=1;j<=17;j++){
			for(llo i=0;i<(1<<17);i++){
				
					if((1<<(j-1))&i){
						dp[jj][i][1]=dp[jj][i][0]+dp[jj][i-(1<<(j-1))][0];
						if(dp[jj][i][1]>=mod){
							dp[jj][i][1]-=mod;
						}
					}
					else{
						dp[jj][i][1]=dp[jj][i][0];
					}

			}
			for(int i=0;i<(1<<17);i++){
				dp[jj][i][0]=dp[jj][i][1];
				dp[jj][i][1]=0;
			}
		}

	}

	int q;
	cin>>q;
	while(q--){
		string ss;
		cin>>ss;
		int su=0;
		for(int j=0;j<ss.size();j++){
			su+=(1<<(ss[j]-'a'));
		}
		/*llo ans=0;
		for(int k=0;k<(1<<17);k++){
			if((k&su)==k){
				ans+=dp[ss.size()][k][0];
				cout<<k<<":"<<dp[2][k][0]<<endl;
			}
		}
		cout<<ans<<endl;*/
		cout<<dp[ss.size()][su][0]<<endl;

	}



 
 
	return 0;
}