#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int n;
int a[N],res[N];
vector<int> A[N];
multiset<int> s;

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		A[i].clear();
	for(int i=1;i<=n;i++){
		cin>>a[i];
		res[i]=a[i];
		s.insert(a[i]);
		A[a[i]].push_back(i);
	}
	while(s.size()){
		int x=*s.begin();s.erase(s.begin());
		int pr=A[x].back();A[x].pop_back();
		auto it=s.upper_bound(x);
		while(it!=s.end()){
			int i=*it;
			s.erase(it);
			int nw=A[i].back();A[i].pop_back();
			swap(res[pr],res[nw]);
			x=i;
			pr=nw;
			it=s.upper_bound(x); 
		}
	}
	for(int i=1;i<=n;i++)
		cout<<res[i]<<' ';
	cout<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}