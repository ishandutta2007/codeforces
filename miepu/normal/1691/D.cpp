#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

int n;
int a[N],mn[N];
int sum[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[0]=1e18;
	stack<int> s;s.push(0);
	multiset<int> S;
	int res=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		int mi=sum[i-1];
		while(a[i]>a[s.top()]){
			S.erase(S.find(mn[s.top()]+a[s.top()]));
			mi=min(mi,mn[s.top()]);
			s.pop(); 
		}
		mn[i]=mi;
		S.insert(mi+a[i]);
		if(sum[i]>*S.begin())
			res=1;
		s.push(i);
		
	}
	cout<<(res?"NO":"Yes")<<endl; 
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}