#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	if (n==1){
		cout<<-1<<endl;
		return 0;
	}
	cout<<n<<" "<<n+1<<" "<<n*(n+1)<<endl;
}