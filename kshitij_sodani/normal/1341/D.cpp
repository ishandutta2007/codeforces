#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

#define pb push_back
#define a first
#define b second
typedef long long llo;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	char s;
	int it[n][7];
	for(int i=0;i<n;i++){
		for(int j=0;j<7;j++){
			cin>>s;
			if(s=='0'){
				it[i][j]=0;
			}
			else{
				it[i][j]=1;
			}
		}
	}
	vector<int> num[10];
	num[0]={1, 1, 1, 0, 1, 1, 1};
	num[1]={0, 0, 1, 0, 0, 1, 0};
	num[2]={1, 0, 1, 1, 1, 0, 1};
	num[3]={1, 0, 1, 1, 0, 1, 1};
	num[4]={0, 1, 1, 1, 0, 1, 0};
	num[5]={1, 1, 0, 1, 0, 1, 1};
	num[6]={1, 1, 0, 1, 1, 1, 1};
	num[7]={1, 0, 1, 0, 0, 1, 0};
	num[8]={1, 1, 1, 1, 1, 1, 1};
	num[9]={1, 1, 1, 1, 0, 1, 1};
/*	int co[10];
	for(int i=0;i<10;i++){
		co[i]=0;
		for(int j=0;j<7;j++){
			co[i]+=num[i][j];
		}
	}*/

	int dp[n+1][k+1];
	for(int i=0;i<k+1;i++){
		dp[n][i]=-1;
	}
	dp[n][0]=0;

	for(int i=n-1;i>=0;i--){
		for(int j=0;j<k+1;j++){
			dp[i][j]=-1;
			for(int kk=9;kk>=0;kk--){
				int st=1;
				int coo=0;
				for(int ll=0;ll<7;ll++){
					if(num[kk][ll]==0 and it[i][ll]==1){
						st=0;
					}
					if(num[kk][ll]==1 and it[i][ll]==0){
						coo+=1;
					}
				}				
				if(st){
					if(j>=coo){
						if(dp[i+1][j-coo]!=-1){
							dp[i][j]=max(dp[i][j],kk);
						}
					}
				}
			}
		}
	}

	if(dp[0][k]==-1){
		cout<<-1<<endl;
	}
	else{
		int tot=k;
		for(int i=0;i<n;i++){
		//	cout<<tot<<" ";
			cout<<dp[i][tot];
			int coo=0;
			int kk=dp[i][tot];
			for(int ll=0;ll<7;ll++){
				if(num[kk][ll]==1 and it[i][ll]==0){
					coo+=1;
				}
			}
			tot-=coo;

		}
		cout<<endl;
	}



	

	return 0;
}