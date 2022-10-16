//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
vector<vector<int> >mul(vector<vector<int> > A,vector<vector<int> > B){
	int sz=A.size();
	vector<vector<int> >C(sz,vector<int>(sz,0));
	for(int i=0;i<sz;i++)for(int j=0;j<sz;j++)C[i][j]=0;
	for(int i=0;i<sz;i++)
		for(int k=0;k<sz;k++)
			for(int j=0;j<sz;j++)
					(C[i][j]+=(ll)A[i][k]*B[k][j]%(mod-1))%=(mod-1);
	return C;
}
vector<vector<int> >fastpow(vector<vector<int> >A,int l){
	vector<vector<int> >B=A;l--;if(!l)return B;
	do{
		if(l&1)B=mul(B,A);
		A=mul(A,A);
	}while(l>>=1);
	return B;
}
vector<vector<int> >mul1{
{0,0,1},
{1,0,1},
{0,1,1},
};
vector<vector<int> >mul2{
{1,1,0,0,0},
{1,0,1,0,0},
{1,0,0,0,0},
{1,0,0,1,0},
{0,0,0,1,1},
};
int n,f1,f2,f3,c;
signed main(){
	cin>>n>>f1>>f2>>f3>>c;
	mul1=fastpow(mul1,n-1);
	mul2=fastpow(mul2,n-3);
	int powf1=mul((vector<vector<int> >){
		{1,0,0},
		{1,0,0},
		{1,0,0}
	},mul1
	)[0][0];
	int powf2=mul((vector<vector<int> >){
		{0,1,0},
		{0,1,0},
		{0,1,0}
	},mul1
	)[0][0];
	int powf3=mul((vector<vector<int> >){
		{0,0,1},
		{0,0,1},
		{0,0,1}
	},mul1
	)[0][0];
	int powc=mul((vector<vector<int> >){
		{0,0,0,2,2},
		{0,0,0,2,2},
		{0,0,0,2,2},
		{0,0,0,2,2},
		{0,0,0,2,2},
	},mul2)[0][0];
//	cerr<<powf1<<" "<<powf2<<" "<<powf3<<" "<<powc<<endl;
	ll ans=1;
	ans*=modpow(f1,powf1);
	ans%=mod;
	ans*=modpow(f2,powf2);
	ans%=mod;
	ans*=modpow(f3,powf3);
	ans%=mod;
	ans*=modpow(c,powc);
	ans%=mod;
	cout<<ans<<endl;
	return 0;
}