#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<list>
#include<bitset>
#include<stack>
#include<memory>
#include<numeric>
#include <utility>

using namespace std;
typedef long long int llint;
llint K=1000000000;
vector<llint>kak(vector<llint>in,int a){
	int n=in.size();
	for(int i=0;i<n;i++){in[i]*=a;}
	if(n==0||in[n-1]>K){in.push_back(0);n++;}
	for(int i=0;i+1<n;i++){
		in[i+1]+=in[i]/K;
		in[i]%=K;
	}
	return in;
}
bool dai(vector<llint>in,vector<llint>jn){
	while(in.size()>0&&in.back()==0){in.pop_back();}
	while(jn.size()>0&&jn.back()==0){jn.pop_back();}
	if(in.size()>jn.size()){return true;}
	if(in.size()<jn.size()){return false;}
	for(int i=((int)in.size())-1;i>=0;i--){
		if(in[i]>jn[i]){return true;}
		if(in[i]<jn[i]){return false;}
	}
	return false;
}
int main(void){
	int n,d,i,h,j;cin>>n>>d;
	vector<int>suu[10];
	for(i=0;i<n;i++){
		int a;cin>>a;
		suu[a%10].push_back(a);
	}
	int mir[10];
	for(h=0;h<10;h++){
		sort(suu[h].begin(),suu[h].end());
		mir[h]=(1+suu[h].size())%4 +3;//4
		if(mir[h]>suu[h].size()){mir[h]=suu[h].size();}
	}
	
	//mir
	vector<llint>dp[10];
	vector<int>da[10];
	dp[1].push_back(1);
	//DP
	for(h=0;h<=9;h++){
		for(i=0;i<mir[h];i++){
			//cerr<<"de"<<endl;
			
			vector<llint>ep[10];
			vector<int>ea[10];
			for(j=0;j<=9;j++){ep[j]=dp[j];ea[j]=da[j];}
			for(j=0;j<=9;j++){
				auto sss=kak(dp[j],suu[h][i]);
				if(dai(sss,ep[h*j%10])){
					ep[h*j%10]=sss;
					ea[h*j%10]=da[j];
					ea[h*j%10].push_back(suu[h][i]);
				}
			}
			for(j=0;j<=9;j++){dp[j]=ep[j];da[j]=ea[j];}
			/*for(j=0;j<=9;j++){
				for(auto it:dp[j]){cerr<<it<<" ";}cerr<<endl;
			}*/
		}
	}
	//da[d]
	vector<int>ans=da[d];
	vector<llint>kra={};
	vector<llint>kkra={0};
	if(dp[d]==kra){cout<<-1<<endl;return 0;}
	if(dp[d]==kkra){cout<<-1<<endl;return 0;}
	if(ans.size()==0){cout<<-1<<endl;return 0;}
	for(i=mir[1];i<suu[1].size();i++){ans.push_back(suu[1][i]);}
	for(i=mir[3];i<suu[3].size();i++){ans.push_back(suu[3][i]);}
	for(i=mir[7];i<suu[7].size();i++){ans.push_back(suu[7][i]);}
	for(i=mir[9];i<suu[9].size();i++){ans.push_back(suu[9][i]);}
	if(d%2==0){
		for(i=mir[2];i<suu[2].size();i++){ans.push_back(suu[2][i]);}
		for(i=mir[4];i<suu[4].size();i++){ans.push_back(suu[4][i]);}
		for(i=mir[6];i<suu[6].size();i++){ans.push_back(suu[6][i]);}
		for(i=mir[8];i<suu[8].size();i++){ans.push_back(suu[8][i]);}
	}
	if(d%5==0){
		for(i=mir[5];i<suu[5].size();i++){ans.push_back(suu[5][i]);}
	}
	if(d%10==0){
		for(i=mir[0];i<suu[0].size();i++){ans.push_back(suu[0][i]);}
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(auto it:ans){cout<<it<<" ";}cout<<endl;
}
/*
6 4
4 11 8 2 1 13
*/