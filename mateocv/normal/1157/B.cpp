#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
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
	ll n; cin>>n;
	string s; cin>>s;
	ll f[10];
	fore(i,1,10)cin>>f[i];
	ll on=0;//l=0;
	fore(i,0,SZ(s)){
		if(!on){
			if(f[0+s[i]-'0']>0+s[i]-'0'){
				on++;
				s[i]=(char)(f[0+s[i]-'0']+'0');
				//l=i;
			}
		}else{
			if(f[0+s[i]-'0']>=0+s[i]-'0'){
				s[i]=(char)(f[0+s[i]-'0']+'0');
			}else{
				break;	
			}
		}
	}
	cout<<s;
	
	return 0;
}