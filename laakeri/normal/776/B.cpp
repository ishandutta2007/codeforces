#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int d[101010];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	if (n<=2){
		cout<<1<<endl;
		for (int j=0;j<n;j++) cout<<1<<" ";
		cout<<endl;
		return 0;
	}
	cout<<2<<endl;
	for (int i=2;i<=n+1;i++){
		if (d[i]==0){
			cout<<1<<" ";
			for (int j=i;j<=n+1;j+=i) d[j]=1;
		}
		else{
			cout<<2<<" ";
		}
	}
	cout<<'\n';
}