#include<bits/stdc++.h>
#define David_eat_ff fflush(stdout)
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
string s;
string interact(string s){
	cout<<"? "<<s<<endl;David_eat_ff;
	string ret;cin>>ret;
	return ret;
}
void submit(string s){
	cout<<"! "<<s<<endl;David_eat_ff;exit(0);
}
int n;
string a,b,c;
int main(){
	cin>>s;n=s.size();
	for(int i=0;i<n;i++){
		a.push_back('a'+i%26);
		b.push_back('a'+i/26%26);
		c.push_back('a'+i/676);
	}
	string s1=interact(a),s2=interact(b),s3=interact(c);
	string ans(n,' ');for(int i=0;i<n;i++)
	ans[s1[i]-'a'+(s2[i]-'a')*26+(s3[i]-'a')*676]=s[i];
	submit(ans);
}