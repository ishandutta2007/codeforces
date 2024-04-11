#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int w[11];
vector<vector<int> >mul(vector<vector<int> >&a,vector<vector<int> >&b){
	vector<vector<int> >ret(a.size(),vector<int>(a.size(),0));
	for(int i=0;i<a.size();i++)for(int j=0;j<a.size();j++)ret[i][j]=0;
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a.size();j++){
			for(int k=0;k<a.size();k++){
				ret[i][j]+=a[i][k]*b[k][j];
				ret[i][j]%=mod;
			}
		}
	}
	return ret;
}
vector<vector<int> >Pow(vector<vector<int> >a,int k){
	vector<vector<int> >ret=a,m=a;k--;
	do{
		if(k&1)ret=mul(ret,m);
		m=mul(m,m);
	}while(k>>=1);
	return ret;
}
int dp[1<<7],tdp[1<<7],pre;
void solve(int x,int times){
	vector<vector<int> >mat((1<<x),vector<int>((1<<x),0));
	for(int st=0;st<(1<<x);st++){
		for(int ed=0;ed<(1<<x);ed++){
			for(int bt=0;bt<(1<<(x-1));bt++){
				int add=1;
				for(int j=0;j<x;j++){
					int cnt=0;
					if(bt&(1<<j)||j==x-1)cnt++;
					if(j==0||(bt&(1<<(j-1))))cnt++;
					if(st&(1<<j))cnt++;
					if(ed&(1<<j))cnt++;
					if(cnt==4)add=0;
				}
				if(add)mat[st][ed]++;
				if(mat[st][ed]>=mod)mat[st][ed]-=mod;
			}
		}
	}
	mat=Pow(mat,times);
	memset(tdp,0,sizeof tdp);
	int or_mask=0;
	for(int i=pre;i<x;i++)or_mask|=(1<<i);
	for(int i=0;i<(1<<x);i++){
		for(int j=0;j<(1<<x);j++){
			tdp[j]+=dp[i]*mat[i|or_mask][j];
			tdp[j]%=mod;
		}
	}
	memcpy(dp,tdp,sizeof tdp);
	pre=x;
}
signed main(){
	for(int i=1;i<=7;i++)cin>>w[i];
	for(int i=1;i<=7;i++){
		if(w[i]){
			dp[(1<<i)-1]=1;
			break;
		}
	}
	for(int i=1;i<=7;i++){
		if(w[i]){
			solve(i,w[i]);
		}
	}
	for(int i=7;i>=1;i--){
		if(w[i]){
			cout<<dp[(1<<i)-1]<<endl;
			return 0;
		}
	}
	return 0;
}