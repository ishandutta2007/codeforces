#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,a,b;
	cin>>n>>a>>b;
	string s;
	cin>>s;
	a--;
	b--;
	if (s[a]==s[b]) {
		cout<<0<<endl;
	}
	else{
		cout<<1<<endl;
	}
}