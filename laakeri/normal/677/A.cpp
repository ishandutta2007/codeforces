#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio();
	cin.tie(0);
	int n,h;
	cin>>n>>h;
	int v=0;
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		if (a>h) v+=2;
		else v++;
	}
	cout<<v<<endl;
}