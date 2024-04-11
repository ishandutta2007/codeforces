#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

vector<int> A;

void solve(){
	A.clear();
	int n,m;cin>>n>>m;
	vector<int> a(m);
	for(auto&x:a)cin>>x;
	sort(a.begin(),a.end());
	for(int i=0;i<m-1;i++){
		A.push_back(a[i+1]-a[i]-1);
	}
	A.push_back(a[0]+n-a[m-1]-1);
	sort(A.begin(),A.end());
	reverse(A.begin(),A.end());
	int k=1;
	int res=0;
	for(auto x:A){
		if(!x)continue;
		if(x<=k){
			if(x==k)res++;
			break;
		}
		res+=x-k;
		k+=4;
	}
	cout<<(n-res)<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}