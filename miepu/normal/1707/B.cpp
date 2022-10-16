#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int a[N],b[N];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int pr=a[n],pp=0;
	int cnt=0;
	for(int k=0;n>1;){
		vector<int> b;
		if(k)b.push_back(a[1]),--k;
		for(int i=1;i<n;i++)
			b.push_back(a[i+1]-a[i]);
		sort(b.begin(),b.end());
		n=0;
		for(auto i:b)
			if(i)a[++n]=i;else ++k;
	}
	cout<<a[n]<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}