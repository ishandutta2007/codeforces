#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){
	int n;
	cin>>n;
	
	vector<vector<int>> A(n,vector<int>(n));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>A[i][j];
		}
	}
	
	vector<vector<pair<int,int>>> dp1(n,vector<pair<int,int>>(n,make_pair(Inf,Inf)));
	vector<vector<pair<int,int>>> dp2 = dp1;
	vector<pair<int,int>> V;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			
			if(A[i][j]==0){
				V.emplace_back(i,j);
				dp1[i][j]=make_pair(1,1);
				dp2[i][j]=make_pair(1,1);
				continue;
			}
			
			int k = A[i][j];
			int cnt_2=0,cnt_5=0;
			while(k%2==0){
				cnt_2++;
				k/=2;
			}
			
			k=A[i][j];
			while(k%5==0){
				cnt_5++;
				k/=5;
			}
			
			if(A[i][j]==0){
				V.emplace_back(i,j);
				dp1[i][j]=make_pair(1,1);
				dp2[i][j]=make_pair(1,1);
				continue;
			}
			
			if(i==0&&j==0){
				dp1[i][j] = make_pair(cnt_2,cnt_5);
				dp2[i][j] = make_pair(cnt_2,cnt_5);
			}
			else if(i==0){
				dp1[i][j] = make_pair(dp1[i][j-1].first+cnt_2,dp1[i][j-1].second+cnt_5);
				dp2[i][j] = make_pair(dp2[i][j-1].first+cnt_2,dp2[i][j-1].second+cnt_5);
			}
			else if(j==0){
				dp1[i][j] = make_pair(dp1[i-1][j].first+cnt_2,dp1[i-1][j].second+cnt_5);
				dp2[i][j] = make_pair(dp2[i-1][j].first+cnt_2,dp2[i-1][j].second+cnt_5);
			}
			else{
				pair<int,int> P1 = dp1[i-1][j],P2 = dp1[i][j-1];
				if(P1<P2){
					dp1[i][j] = P1;
				}
				else{
					dp1[i][j] = P2;
				}
				dp1[i][j].first += cnt_2;
				dp1[i][j].second += cnt_5;
				
				P1 = dp2[i-1][j],P2 = dp2[i][j-1];
				swap(P1.first,P1.second);
				swap(P2.first,P2.second);
				if(P1<P2){
					swap(P1.first,P1.second);
					dp2[i][j]=P1;
				}
				else{
					swap(P2.first,P2.second);
					dp2[i][j]=P2;
				}
				
				dp2[i][j].first+=cnt_2;
				dp2[i][j].second += cnt_5;
				
			}
		}
	}
	
	int ans = min({dp1[n-1][n-1].first,dp1[n-1][n-1].second,dp2[n-1][n-1].first,dp2[n-1][n-1].second});
	
	if(ans>=1&&V.size()!=0){
		int x = V[0].second;
		int y = V[0].first;
		cout<<1<<endl;
		for(int i=0;i<x;i++){
			cout<<'R';
		}
		for(int i=0;i<n-1;i++){
			cout<<'D';
		}
		for(int i=0;i<n-1-x;i++){
			cout<<'R';
		}
		cout<<endl;
	}
	else{
		cout<<ans<<endl;
		string X = "";
		if(min(dp1[n-1][n-1].first,dp1[n-1][n-1].second)!=ans){
			swap(dp1,dp2);
		}
		
		int y = n-1,x = n-1;
		while(true){
			if(x==0&&y==0)break;
			if(y==0){
				x--;
				X+='R';
				continue;
			}
			if(x==0){
				y--;
				X+='D';
				continue;
			}
			
			int k = A[y][x];
			int cnt_2=0,cnt_5=0;
			while(k%2==0){
				cnt_2++;
				k/=2;
			}
			
			k=A[y][x];
			while(k%5==0){
				cnt_5++;
				k/=5;
			}
			
			if(dp1[y][x-1].first + cnt_2 == dp1[y][x].first && dp1[y][x-1].second + cnt_5 == dp1[y][x].second){
				x--;
				X+='R';
			}
			else{
				y--;
				X+='D';
			}
		}
		reverse(X.begin(),X.end());
		cout<<X<<endl;
			

	}
	
	return 0;
}