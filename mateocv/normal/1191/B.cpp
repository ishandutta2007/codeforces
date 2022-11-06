#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	string s[3];
	fore(k,0,3)cin>>s[k];
	sort(s,s+3);
	if(s[0]==s[2]){
		cout<<0; return 0;
	}
	if(s[0][0]+1==s[1][0]&&s[1][0]+1==s[2][0]&&s[0][1]==s[1][1]&&s[1][1]==s[2][1]){
		cout<<0; return 0;
	}
	if(s[0]==s[1]||s[1]==s[2]){
		cout<<1; return 0;
	}
	fore(i,0,3){
		if(s[i][1]==s[(i+1)%3][1]&&abs(s[i][0]-s[(i+1)%3][0])<=2){
			cout<<1; return 0;
		}
	}
	cout<<2;
	return 0;
}