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
	int n;
	cin>>n;
	int v=1e9;
	for (int i=1;i*i<=2*n;i++){
		int a=i;
		int b=n/a+(n%a>0);
		v=min(v, a*2+b*2);
	}
	cout<<v<<endl;
}