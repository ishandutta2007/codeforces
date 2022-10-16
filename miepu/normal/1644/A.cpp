#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	string s;
	vector<int> pos(200);
	cin>>s;
	int i=0;
	for(auto x:s){
		pos[x]=++i;
	}
	int fl=1;
	if(pos['r']>pos['R'])fl=0;
	if(pos['g']>pos['G'])fl=0;
	if(pos['b']>pos['B'])fl=0;
	cout<<(fl?"YES":"NO")<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}