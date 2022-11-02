#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int wow[300];
int p[300];

void solve(int pp, string s){
	int c=0;
	for (int i=0;i<(int)s.size();i++){
		c+=wow[s[i]];
	}
	if (c!=pp){
		cout<<"NO\n";
		exit(0);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	wow['a']=1;
	wow['e']=1;
	wow['i']=1;
	wow['o']=1;
	wow['u']=1;
	wow['y']=1;
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>p[i];
	}
	string s;
	getline(cin, s);
	for (int i=0;i<n;i++){
		getline(cin, s);
		solve(p[i], s);
	}
	cout<<"YES"<<endl;
}