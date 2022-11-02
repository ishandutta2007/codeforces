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
	ll k,a,b;
	cin>>k>>a>>b;
	if (a<k&&b<k){
		cout<<-1<<endl;
		return 0;
	}
	if (a/k==0&&b%k>0){
		cout<<-1<<endl;
		return 0;
	}
	if (b/k==0&&a%k>0){
		cout<<-1<<endl;
		return 0;
	}
	cout<<a/k+b/k<<endl;
}