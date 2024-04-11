#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	string s; cin>>s;
	ll l=0,r=SZ(s)-1;
	if(r%2==0)r--;
	string res;
	while(r-l>=3){
		if(s[l]==s[r])res+=s[l];
		else if(s[l]==s[r-1])res+=s[l];
		else if(s[l+1]==s[r])res+=s[l+1];
		else if(s[l+1]==s[r-1])res+=s[l+1];
		l++; l++;
		r--; r--;
	}
	cout<<res;
	if(r-l==1)cout<<s[l];
	reverse(ALL(res));
	cout<<res;
	
	return 0;
}