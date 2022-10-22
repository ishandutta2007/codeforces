#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000



int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int n,m;
		cin>>n>>m;
		

		vector<pair<int,pair<int,int>>> A(n*m);
		
				
		
		vector<deque<int>> a(n,deque<int>(m));
		
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				scanf("%d",&a[j][k]);
				A[j*m+k].first=a[j][k];
				A[j*m+k].second.first=j;
				A[j*m+k].second.second=k;
			}
		}
		
		sort(A.begin(),A.end());
		reverse(A.begin(),A.end());
		
		vector<deque<int>> D(0);
		set<int> S;
		
		for(int j=0;j<n*m;j++){
			if(S.count(A[j].second.second))continue;
			D.push_back(deque<int>());
			for(int k=0;k<n;k++){
				D[D.size()-1].push_back(a[k][A[j].second.second]);
			}

			S.insert(A[j].second.second);
			if(S.size()==n)break;
		}
		
		vector<vector<int>> dp(D.size()+1,vector<int>((1<<n),0));
		for(int j=0;j<D.size();j++){
			for(int k=0;k<(1<<n);k++){
				for(int rot = 0;rot < n;rot ++){
					int x = D[j][0];
					D[j].pop_front();
					D[j].push_back(x);
					int add = 0;
					int now = k;
					for(int X = 0;X<n;X++){
						if((now&(1<<X))==0)continue;
						if(-dp[j][now]+dp[j][(now^(1<<X))]+D[j][X]>0){
							add += -dp[j][now]+dp[j][(now^(1<<X))]+D[j][X];
							now ^= (1<<X);
						}
						//add += max(-dp[j][now]+dp[j][(now^(1<<X))]+D[j][X],0);
						if(j==1&&k==3){
							//cout<<D[j][X]<<','<<add<<endl;
						}
					}
					dp[j+1][k] = max(dp[j+1][k],dp[j][k]+add);
					//if(j==0)cout<<dp[j+1][k]<<endl;
					
				}
				
				
			}
		}
		/*
		for(int j=0;j<D.size();j++){
			for(int k=0;k<D[j].size();k++){
				cout<<D[j][k]<<',';
			}
			cout<<endl;
		}*/
		
		/*
		for(int j=0;j<=D.size();j++){
			for(int k=0;k<(1<<n);k++){
				cout<<dp[j][k]<<',';
			}
			cout<<endl;
		}
		*/
		cout<<dp[D.size()][(1<<n)-1]<<endl;
		
		
		
	}
		
	
	
	return 0;
}