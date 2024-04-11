#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	set<string> a;
	string s,t;
	cin>>s>>t;
	a.insert(s);
	a.insert(t);
	int n;
	cin>>n;
	cout<<s<<" "<<t<<endl;
	for (int i=0;i<n;i++){
		cin>>s>>t;
		a.erase(s);
		a.insert(t);
		for (auto aa:a){
			cout<<aa<<" ";
		}
		cout<<'\n';
	}
}