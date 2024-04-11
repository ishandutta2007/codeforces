#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int get(char c){
	if (c>='0'&&c<='9'){
		return c-'0';
	}
	else if (c>='A'&&c<='Z'){
		return c-'A'+10;
	}
	else if (c>='a'&&c<='z'){
		return c-'a'+36;
	}
	else if(c=='-') return 62;
	else return 63;
}

const ll mod=1e9+7;
ll pot(ll x, ll p){
	if (p==0) return 1;
	if (p%2==0){
		x=pot(x, p/2);
		return (x*x)%mod;
	}
	return (x*pot(x, p-1))%mod;
}

int main() {
	ios_base::sync_with_stdio();
	cin.tie(0);
	string s;
	cin>>s;
	int n=s.size();
	int pc=0;
	for (char t:s){
		pc+=__builtin_popcount(get(t));
	}
	cout<<pot(3, n*6-pc)<<endl;
}