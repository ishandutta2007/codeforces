//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int it[200001][61];
int val[1<<16];
int aa[1<<16];
int dp[1<<16][16];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	mt19937 rng;
	rng=mt19937(chrono::steady_clock::now().time_since_epoch().count());


	int n,m,p;
	cin>>n>>m>>p;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<m;j++){
			it[i][j]=s[j]-'0';
		}

	}
	vector<int> ans;
	for(int j=0;j<(1<<15);j++){
		aa[j]=__builtin_popcount(j);
	}
	int ma=0;
	for(int i=0;i<m;i++){
		ans.pb(0);
	}
	for(int ii=0;ii<60;ii++){
		int x=rng()%n;
		vector<int> xx;
		for(int j=0;j<m;j++){
			if(it[x][j]==1){
				xx.pb(j);
			}
		}
		if(xx.size()==0){
			continue;
		}
		int nn=xx.size();
		for(int j=0;j<(1<<nn);j++){
			val[j]=0;
		}
		for(int j=0;j<n;j++){
			int val2=0;
			int ind=-1;
			for(auto k:xx){
				ind++;
				if(it[j][k]==1){
					val2+=(1<<ind);
				}
			}
			val[(1<<nn)-1-val2]+=1;
		}
		int ma2=0;
		int ma3=0;
		/*for(int j=(1<<nn)-1;j>=1;j--){
			int yy=val[j];
			for(int i=0;i<nn;i++){
				if((1<<i)&j){

				}
				else{
					val[j]=max(val[j],val[j+(1<<i)]+yy);
				}
			}
			if(val[j]>=((n+1)/2)){
				if(aa[j]>ma2){
					ma2=aa[j];
					ma3=j;
				}
			}
		}*/

		for(llo i=0;i<(1<<nn);i++){
 			dp[i][0]=val[i];
			for(int j=1;j<=nn;j++){
				dp[i][j]=dp[i][j-1];
				if(i&(1<<(j-1))){
					dp[i][j]+=dp[i^(1<<(j-1))][j-1];
				}
			}
			if(dp[i][nn]>=(n+1)/2){
				int kk=aa[(1<<nn)-1-i];
			//	if(kk>=((n+1)/2)){
					if(kk>ma2){
						ma2=kk;
						ma3=(1<<nn)-1-i;
					}
				//}
			}
		}

		if(ma2>ma){
			ma=ma2;
			ans.clear();
			for(int i=0;i<m;i++){
				ans.pb(0);
			}
			for(int i=0;i<nn;i++){
				if((1<<i)&ma3){
					ans[xx[i]]=1;
				}
			}
		}
	}
	for(auto j:ans){
		cout<<j;
	}
	cout<<endl;







	return 0;
}