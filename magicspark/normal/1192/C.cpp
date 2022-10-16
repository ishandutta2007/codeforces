#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n;
set<string>len[12];
int cnt[64][64][64];
int c[66][66];
int ans=0;
const int _=62;
inline int getid(char c){
	if(c<='z'&&c>='a')return c-'a';
	if(c<='Z'&&c>='A')return 26+c-'A';
	return 52+c-'0';
}
inline int Calc3(int a,int b,int c){
	if(a==b&&b==c)return 1;
	if(a==b||b==c)return 3;
	return 6;
}
inline int Calc4(int a,int b,int c,int d){
	if(a==b&&b==c&&c==d)return 1;
	if(b==c&&(a==b||c==d))return 4;
	if(a==b&&c==d)return 6;
	if(a==b||b==c||c==d)return 12;
	return 24;
}
void calc(vector<string>v){
	if(!v.size())return;
	memset(cnt,0,sizeof cnt);
	memset(c,0,sizeof c);
	for(auto s:v){
//		cerr<<s<<" "<<getid(s[0])<<" "<<getid(s.back())<<endl;
		c[getid(s[0])][getid(s.back())]++;
	}
	for(int i=0;i<_;i++)for(int j=i;j<_;j++)for(int k=j;k<_;k++)for(int l=0;l<_;l++){
		cnt[i][j][k]=(cnt[i][j][k]+c[l][i]*c[l][j]%mod*c[l][k]%mod)%mod;
	}
	for(int i=0;i<_;i++)for(int j=i;j<_;j++)for(int k=j;k<_;k++)for(int l=k;l<_;l++){
		long long add=1;
		add=add*cnt[i][j][k]%mod;
		add=add*cnt[i][j][l]%mod;
		add=add*cnt[i][k][l]%mod;
		add=add*cnt[j][k][l]%mod;
		add=add*Calc4(i,j,k,l)%mod;
		(ans+=add)%=mod;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;cin>>s;len[s.size()].insert(s);
		reverse(s.begin(),s.end());len[s.size()].insert(s);
	}
	for(int i=2;i<=10;i++){vector<string>vec(len[i].begin(),len[i].end());calc(vec);}
	cout<<ans<<endl;
	return 0;
}