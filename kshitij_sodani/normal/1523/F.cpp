//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int n,m;
pair<int,int> aa[20];
pair<int,int> bb[101];
int tt[101];
int dp[101][1<<14];//max value
int dp2[101][1<<14];//min time
int dist[101][101];
int dist2[1<<14][120];
int dp3[101][1<<14];
int ind[1<<14];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>aa[i].a>>aa[i].b;
	}
	vector<pair<int,pair<int,int>>> ss;
	for(int i=0;i<m;i++){
		int bbb,ccc,ttt;
		cin>>bbb>>ccc>>ttt;
		ss.pb({ttt,{bbb,ccc}});
	}
	sort(ss.begin(),ss.end());
	for(int i=0;i<m;i++){
		bb[i]=ss[i].b;
		tt[i]=ss[i].a;
	}	
	for(int i=0;i<=m;i++){
		for(int j=0;j<(1<<n);j++){
			dp2[i][j]=1e9+1;
			
		}


	}
	dp2[0][0]=0;
	for(int j=0;j<n;j++){
		dp2[0][1<<j]=0;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<(1<<n);j++){
			dp[i][j]=-1e9;
			if(j==0){
				dp[i][j]=1;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			dist[i][j]=abs(bb[i].a-bb[j].a)+abs(bb[i].b-bb[j].b);
		}
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n+m;j++){
			pair<int,int> cur;
			if(j<n){
				cur=aa[j];
			}
			else{
				cur=bb[j-n];
			}
			dist2[i][j]=1e9;
			for(int jj=0;jj<n;jj++){
				if((1<<jj)&i){
					dist2[i][j]=min(dist2[i][j],abs(aa[jj].a-cur.a)+abs(aa[jj].b-cur.b));
				}
			}
		}
	}

	for(int i=0;i<m;i++){
		//update from previous dp2[arrays];
		//fast to fast update

		//for(int jj=0;jj<=i;jj++){
			for(int j=0;j<(1<<n);j++){
				if(ind[j]>=m+1){
					continue;
				}
				while(ind[j]<=i){
					int jj=ind[j];
					if(dp2[jj][j]>=tt[i]){
						break;
					}
					if(dp2[jj][j]>=0){

						for(int kk=0;kk<n;kk++){
							if((1<<kk)&j){

							}
							else{
								dp2[jj][j+(1<<kk)]=min(dp2[jj][j]+dist2[j][kk],dp2[jj][j+(1<<kk)]);
							}
						}
						ind[j]++;
					}
					else{
						break;
					}
				}

				/*if(dp2[jj][j]>=tt[i]){
					continue;
				}*/
				/*if(i>0 and dp3[jj][j]==dp2[jj][j]){
					continue;
				}*/
				

			}
		//}
		for(int jj=0;jj<=i;jj++){
			for(int j=0;j<(1<<n);j++){
				dp3[jj][j]=dp2[jj][j];
			}
		}
		/*if(i==0){
			cout<<dp2[0][1]<<endl;
			cout<<dist2[1][n+0]<<endl;
		}*/
		//tower to current quest update
		for(int jj=0;jj<=i;jj++){
			for(int j=1;j<(1<<n);j++){
				if(dp2[jj][j]+dist2[j][i+n]<=tt[i]){
					dp[i][j]=max(dp[i][j],jj+1);
				}
			}
		}
		//quest to quest update
		for(int j=0;j<(1<<n);j++){
			for(int jj=i+1;jj<m;jj++){	
				
				if(dist[i][jj]<=tt[jj]-tt[i]){
					dp[jj][j]=max(dp[jj][j],dp[i][j]+1);
				}
			}
		}


	/*	for(int j=0;j<(1<<n);j++){
			for(int jj=i+1;jj<m;jj++){	
				if(dist[i][jj]<=tt[j]-tt[i]){
					dp[jj][j]=max(dp[jj][j],dp[i][j]+1);
				}
			}
		}
*/
		//when calculated values do quest to quest update
		//quest to fast update

		//quest to tower update
		for(int j=0;j<(1<<n);j++){
			if(dp[i][j]>=0){
				dp2[dp[i][j]][j]=min(dp2[dp[i][j]][j],tt[i]);
			}
		}
		for(int j=0;j<(1<<n);j++){
			if(dp[i][j]>=0){
				for(int jj=0;jj<n;jj++){
					if((1<<jj)&j){
					}
					else{
						dp2[dp[i][j]][j+(1<<jj)]=min(dp2[dp[i][j]][j+(1<<jj)],tt[i]+abs(bb[i].a-aa[jj].a)+abs(bb[i].b-aa[jj].b));
					}
				}
			}
		}
		
	}
	int ans=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<(1<<n);j++){
			ans=max(ans,dp[i][j]);
			//cout<<dp[i][j]<<",";
		}
	//	cout<<endl;
	}


	cout<<ans<<endl;









	return 0;
}