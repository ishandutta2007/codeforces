/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#endif
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
string s;int n;
int cnt[100005][3];
int main(){
	cin>>s;n=s.size();s=" "+s;
	for(int i=n;i>=1;i--){
		for(int j=0;j<3;j++)cnt[i][j]=cnt[i+1][j];
		cnt[i][(s[i]-'0')%3]++;
	}
	int ans=n,ii,oo,tt;
	for(int i=0;i<n;i++){
		if(s[i+1]=='0')continue;
		for(int one=0;one<=min(2,cnt[i+2][1]);one++){
			for(int two=0;two<=min(2,cnt[i+2][2]);two++){
				int rem=1*(cnt[i+2][1]-one)+2*(cnt[i+2][2]-two)+(s[i+1]-'0');rem%=3;
				if(rem==0&&i+one+two<ans){
					ans=i+one+two;
					ii=i;oo=one;tt=two;
				}
			}
		}
	}
	if(ans==n&&s.find('0')<=1e6){
		puts("0");return 0;
	}
	if(ans>=n)puts("-1");
	else{
		string out=getstr(s,ii+1,n);
		reverse(out.begin(),out.end());
		for(int i=0;i<=9;i++){
			while(i%3==1&&oo&&out.find('0'+i)<=1e6){
				out.erase(out.find('0'+i),1);oo--;
			}
			while(i%3==2&&tt&&out.find('0'+i)<=1e6){
				out.erase(out.find('0'+i),1);tt--;
			}
		}
		reverse(out.begin(),out.end());
		cout<<out<<endl;
	}
	return 0;
}