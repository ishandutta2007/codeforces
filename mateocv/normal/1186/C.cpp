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
	string a,b; cin>>a>>b;
	ll s[SZ(a)+1];
	s[0]=0;
	fore(i,1,SZ(a)+1){
		s[i]=(s[i-1]+(a[i-1]-'0'))%2;
	}
	ll sum=0;
	fore(i,0,SZ(b)){
		sum+=(b[i]=='1');
	}
	//cout<<sum<<" ";
	//fore(i,0,SZ(a)+1)cout<<s[i]<<" "; cout<<"\n";
	ll res=0;
	if(SZ(b)%2){
		fore(i,SZ(b),SZ(a)+1){
			if((sum+s[i]-s[i-SZ(b)])%2==0)res++;
		}
	}else{
		fore(i,SZ(b),SZ(a)+1){
			if((sum+s[i]-s[i-SZ(b)])%2==0)res++;
		}
	}
	cout<<res;
	return 0;
}