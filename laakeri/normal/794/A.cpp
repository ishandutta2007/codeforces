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
	int a,b,c;
	cin>>a>>b>>c;
	int n;
	cin>>n;
	int v=0;
	for (int i=0;i<n;i++){
		int x;
		cin>>x;
		if (x>b&&x<c) v++;
	}
	cout<<v<<endl;
}