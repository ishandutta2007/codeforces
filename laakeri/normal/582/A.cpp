#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int h[555];

int git=0;

map<int, int> c;

void use(int x){
	h[git]=x;
	c[x]--;
	for (int i=0;i<git;i++){
		c[__gcd(h[i], h[git])]-=2;
	}
	git++;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> lol;
	for (int i=0;i<n*n;i++){
		int a;
		cin>>a;
		lol.push_back(a);
		c[a]++;
	}
	sort(lol.begin(), lol.end());
	lol.erase(unique(lol.begin(), lol.end()), lol.end());
	for (int i=(int)lol.size()-1;i>=0;i--){
		if (git>=n) break;
		while (c[lol[i]]>0){
			use(lol[i]);
		}
	}
	for (int i=0;i<n;i++){
		cout<<h[i]<<" ";
	}
}