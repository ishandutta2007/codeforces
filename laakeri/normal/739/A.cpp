#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int le=n;
	for (int i=0;i<m;i++){
		int l,r;
		cin>>l>>r;
		le=min(le, r-l+1);
	}
	cout<<le<<endl;
	for (int i=0;i<n;i++){
		cout<<i%le<<" ";
	}
}