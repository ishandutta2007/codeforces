#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;i++)
#define SZ(a) ((int)(a).size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second
#define pb push_back

int main() {FIN;
	string s; cin>>s;
	int l=0,r=SZ(s)-1,ans=0;
	while(l<=r){
		char c=s[l]; int am1=0,am2=0;
		while(l<=r&&s[l]==c)l++,am1++;
		while(l<=r&&s[r]==c)r--,am2++;
		if(l<=r&&am1+am2<3) break;
		if(l<=r&&(!am1||!am2))break;
		am1+=am2;
		if(l>r&&am1>1) ans=am1+1;
	}
	cout<<ans<<"\n";
}