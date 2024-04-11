//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

const llo mod=998244353 ;

llo dp[8][1000001];
llo dp2[1000001];
llo it[10];
//[300001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(llo i=0;i<7;i++){
		for(llo j=0;j<1000000;j++){
			dp[i][j]=-1e18;
		}
	}

	llo k;
	cin>>k;
	for(llo i=0;i<6;i++){
		cin>>it[i];
	}

	dp[0][0]=0;
	llo cur=1;
	deque<pair<llo,int>> ss;
	for(llo i=1;i<7;i++){
		/*for(llo j=0;j<cur*3;j++){
			ss[j].clear();
		}*/
		//ss.clear();
		llo xx=0;
		llo yy=cur*3;
		//continue;
		for(int jj=0;jj<yy;jj++){
			xx=jj;
			ss.clear();
			for(int j=jj;j<1000000;j+=yy){
				llo x=dp[i-1][j]-(j/yy)*it[i-1];
				while(ss.size()){
					if(ss.back().a<=x){
						ss.pop_back();
					}
					else{
						break;
					}
				}
				while(ss.size()){
					if(ss.front().b<j-cur*9*(k-1)){
						ss.pop_front();
					}
					else{
						break;
					}
				}
				ss.pb({x,j});

				dp[i][j]=ss.front().a+((j/yy)*it[i-1]);
			}
		}
		/*for(llo j=0;j<1000000;j++){
			
			xx++;
			if(xx==cur*3){
				xx=0;
			}
		}*/
		//continue;
		//continue;
		for(llo j=0;j<1000000;j++){
			dp2[j]=-1e18;
		}
		for(llo j=0;j<1000000;j++){
			for(llo k=0;k<10;k++){
				llo val=0;
				if(k%3==0){
					val=(k/3)*(it[i-1]);
				}
				if(j+cur*k<1000001){
					dp2[j+cur*k]=max(dp2[j+cur*k],dp[i][j]+val);
				}
			}
		}
		for(llo j=0;j<1000000;j++){
			dp[i][j]=dp2[j];
		}
		cur*=10;
	}
	//cout<<11<<endl;
	//return 0;
	llo q;
	cin>>q;
	while(q--){
		llo x;
		cin>>x;
		cout<<dp[6][x]<<endl;
	}






	return 0;
}