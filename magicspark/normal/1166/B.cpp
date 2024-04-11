#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int k;
vector<string>ans;
string _="aeiou";
int main(){
	cin>>k;
	for(int i=5;i<=k;i++)if(k/i>=5&&k%i==0){
		string pre="",s="";
		for(int j=1;j<=i;j++)s.push_back(_[j%5]);
		for(int j=1;j<=k/i;j++){
			s.push_back(s[0]);s.erase(s.begin());
			cout<<s;
		}
		return 0;
	}
	puts("-1");
	return 0;
}