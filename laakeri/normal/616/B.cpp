#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int v=0;
	for (int i=0;i<n;i++){
		int mic=1e9;
		for (int ii=0;ii<m;ii++){
			int a;
			cin>>a;
			mic=min(mic, a);
		}
		v=max(v, mic);
	}
	cout<<v<<endl;
}