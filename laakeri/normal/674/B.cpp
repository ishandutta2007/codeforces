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
	int n,k;
	cin>>n>>k;
	if (n==4||k<n+1){
		cout<<-1<<endl;
		return 0;
	}
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<a<<" "<<c<<" ";
	for (int i=1;i<=n;i++){
		if (i!=a&&i!=b&&i!=c&&i!=d) cout<<i<<" ";
	}
	cout<<d<<" "<<b<<" ";
	cout<<endl;
	cout<<c<<" "<<a<<" ";
	for (int i=1;i<=n;i++){
		if (i!=a&&i!=b&&i!=c&&i!=d) cout<<i<<" ";
	}
	cout<<b<<" "<<d<<" ";
	cout<<endl;
}