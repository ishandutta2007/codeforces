#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

map<int,int> cnt,nc;
int n,s,fl=1,C;

void push(int x){
	if(C>n){
		fl=0;
		return ;
	}
	if(nc[x]<cnt[x])
		nc[x]++;
	else if(x>1)
		C++,push(x/2),push((x+1)/2);
	else fl=0;
}

void solve(){
	cin>>n;
	s=0;
	fl=1;
	C=0;
	cnt.clear();
	nc.clear();
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		cnt[x]++;
		s+=x;
	}
	push(s);
	cout<<(fl?"YES":"NO")<<endl;
}
main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}