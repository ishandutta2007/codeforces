#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

ll n;

int p[1010101];

ll cnt(vector<int> t){
	for (int i=0;i<2*n;i++){
		p[t[i]]=-1;
	}
	ll s=0;
	for (int i=0;i<2*n;i++){
		if (p[t[i]]==-1){
			p[t[i]]=i;
		}
		else{
			s+=(n-t[i])*abs(i-p[t[i]]+t[i]-n);
		}
	}
	return s;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	if (n%2==0){
		for (int i=1;i<n;i+=2){
			cout<<i<<" ";
		}
		for (int i=n-1;i>=1;i-=2){
			cout<<i<<" ";
		}
		for (int i=2;i<=n;i+=2){
			cout<<i<<" ";
		}
		for (int i=n-2;i>=2;i-=2){
			cout<<i<<" ";
		}
		cout<<n<<endl;
	}
	else{
		for (int i=1;i<=n;i+=2){
			cout<<i<<" ";
		}
		for (int i=n-2;i>=1;i-=2){
			cout<<i<<" ";
		}
		for (int i=2;i<n;i+=2){
			cout<<i<<" ";
		}
		for (int i=n-1;i>=2;i-=2){
			cout<<i<<" ";
		}
		cout<<n<<endl;
	}
	/*
	vector<int> t;
	for (int i=1;i<=n;i++){
		t.push_back(i);
		t.push_back(i);
	}
	ll v=1e9;
	while (1){
		v=cnt(t);
		if (v==0){
			for (int i=0;i<2*n;i++){
				cout<<t[i]<<" ";
			}
			cout<<endl;
		}
		if (!next_permutation(t.begin(), t.end())) break;
	}
	*/
}