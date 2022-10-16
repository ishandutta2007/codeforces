#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
using namespace std;
const int inf=0x3f3f3f3f;
const long long inf2=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
int n,m;
int g[123][123];
vector<string> ans;
string turn_str(int x){
	string re="";
	if(x==0)return "0";
	while(x){
		re.push_back('0'+x%10);
		x/=10;
	}
	reverse(re.begin(),re.end());
	return re;
}
int main(){
	ios::sync_with_stdio();
	cin>>n>>m;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>g[i][j];
	if(n<m){
		//hang
		for(int i=0;i<n;i++){
			int mn=inf;
			for(int j=0;j<m;j++)mn=min(mn,g[i][j]);
			for(int j=0;j<mn;j++)ans.push_back("row "+turn_str(i+1));
			for(int j=0;j<m;j++)g[i][j]-=mn;
		}
		for(int j=0;j<m;j++){
			int mn=inf;
			for(int i=0;i<n;i++)mn=min(mn,g[i][j]);
			for(int i=0;i<mn;i++)ans.push_back("col "+turn_str(j+1));
			for(int i=0;i<n;i++)g[i][j]-=mn;
		}
	}
	else{
		//lie
		for(int j=0;j<m;j++){
			int mn=inf;
			for(int i=0;i<n;i++)mn=min(mn,g[i][j]);
			for(int i=0;i<mn;i++)ans.push_back("col "+turn_str(j+1));
			for(int i=0;i<n;i++)g[i][j]-=mn;
		}
		for(int i=0;i<n;i++){
			int mn=inf;
			for(int j=0;j<m;j++)mn=min(mn,g[i][j]);
			for(int j=0;j<mn;j++)ans.push_back("row "+turn_str(i+1));
			for(int j=0;j<m;j++)g[i][j]-=mn;
		}
	}
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(g[i][j]!=0){
		cout<<-1<<endl;
		return 0;
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	#ifndef ONLINE_JUDGE
		printf("\n-----\n");
        printf("Time: %d ms\n", (int)(clock() * 1000/ CLOCKS_PER_SEC));
    #endif
	return 0;
}