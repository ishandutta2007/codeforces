#include<bits/stdc++.h>
const int N=1000005,mod=32768;
using namespace std;

int f[N],v[N];
queue<int>q;
int chk(int k){
	return (k%mod+mod)%mod;
}
void add(int x,int y){
	if(v[x])return ;
	v[x]=1;
	q.push(x);
	f[x]=y;
}
void solve(){
	int x;cin>>x;
	cout<<f[x]<<' ';
}

main(){
	q.push(0);
	v[0]=1;
	while(q.size()){
		int nw=q.front();q.pop();
		add(chk(nw-1),f[nw]+1);
		if(nw&1)continue;
		add(nw/2,f[nw]+1);
		add((nw+mod)/2,f[nw]+1); 
	}
	int _T=1;cin>>_T;
	while(_T--)solve();
}