#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int T;
string s;
inline bool check(string _s){
	for(int i=1;i<_s.size();i++){
		if((int)_s[i]-_s[i-1]==1 || (int)_s[i]-_s[i-1]==-1)return false;
	}
	return true;
}
int main(){
	cin>>T;
	while(T--){
		cin>>s;
		string even="",odd="";
		for(char c:s){
			if(c&1)odd.push_back(c);
			else even.push_back(c);
		}
		sort(even.begin(),even.end());
		sort(odd.begin(),odd.end());
		cerr<<odd<<" "<<even<<endl;
		if(check(odd+even))cout<<odd+even<<endl;
		else if(check(even+odd))cout<<even+odd<<endl;
		else cout<<"No answer"<<endl;
	}
	return 0;
}