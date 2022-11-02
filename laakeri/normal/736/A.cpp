#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll ans[222];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	ans[1]=2;
	ans[2]=3;
	for (int i=3;i<200;i++){
		ans[i]=ans[i-2]+ans[i-1];
	}
	for (int i=1;i<200;i++){
		if (ans[i]>n){
			cout<<i-1<<endl;
			return 0;
		}
	}
}