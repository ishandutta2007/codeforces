#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n;string s;
	cin>>n>>s;
	int fl=-1,fl2=0,cnt=0;
	int res=0,rst=n;
	for(int i=0;i<n;i++){
		if(fl2==1&&s[i]=='('){
			cnt++;
			continue;
		}
		if(fl2==1&&s[i]==')'){
			res++;
			rst-=cnt;
			fl2=0;
			fl=-1;
			continue;
		}
		if(fl==-1){
			fl=s[i];
			continue;
		}
		if(s[i]==fl){
			res++;
			rst-=2;
			fl=-1;
			continue;
		}
		if(s[i]==')'){
			res++;
			rst-=2;
			fl=-1;
			continue;
		}
		fl2=1;
		cnt=3;
	}
	cout<<res<<' '<<rst<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}