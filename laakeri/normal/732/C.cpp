#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll b,d,s;
	cin>>b>>d>>s;
	ll v=0;
	v+=max(0ll, max(b, max(d, s))-1ll-b);
	v+=max(0ll, max(b, max(d, s))-1ll-d);
	v+=max(0ll, max(b, max(d, s))-1ll-s);
	cout<<v<<endl;
}