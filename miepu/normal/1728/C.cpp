#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int lg(int k){
	int res=1,p=10;
	while(k>=p)res++,p*=10;
	return res;
}

void solve(){
	priority_queue<int> a,b;
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		a.push(x); 
	}
	
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		b.push(x); 
	}
	
	int res=0;
	while(a.size()&&b.size()){
		if(a.top()==b.top()){
			a.pop();b.pop();
			continue;
		}
		res++;
		if(a.top()>b.top()){
			a.push(lg(a.top()));
			a.pop();
		}else{
			b.push(lg(b.top()));
			b.pop();
		}
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}