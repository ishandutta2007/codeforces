#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,t,cnta,cntb;
int a[200005],b[200005],dp[200005];
char get_char(string &s){
	char ret=s.back();s.pop_back();
	return ret;
}
void print(int x){
	if(x==1){
		a[cnta]++;
		for(int i=cnta;i>=1;i--){
			if(a[i]==10){
				a[i-1]++;
				a[i]-=10;
			}
		}
		if(a[0])putchar('0'+a[0]);
		for(int i=1;i<=cnta;i++)putchar('0'+a[i]);
	}else{
		for(int i=1;i<=cnta;i++)putchar('0'+a[i]);
//		cerr<<"integer\n";
		putchar('.');
//		cerr<<"point\n";
		for(int i=1;i<x-1;i++)putchar('0'+b[i]);
		putchar('0'+b[x-1]+1);
	}
}
int main(){
	cin>>n>>t;
	cerr<<"htc ak ioi\n";
	string s;cin>>s;string T=s;
	reverse(s.begin(),s.end());
	bool B=false;
	for(int i=1;i<=n;i++){
		char c=get_char(s);
		if(c=='.'){
			B=true;
			continue;
		}
		(B?b[++cntb]:a[++cnta])=c-'0';
	}
	memset(dp,inf,sizeof dp);
	for(int i=cntb;i>=1;i--){
		if(b[i]>=5){
			dp[i]=1;
		}else if(b[i]==4){
			dp[i]=min(dp[i],dp[i+1]+1);
		}
	}
	for(int i=1;i<=cntb;i++){
		if(dp[i]<=t){
			print(i);
			return 0;
		}
	}
	cout<<T<<endl;
	return 0;
}