#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

const int M=100000;
int c[2*M];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		c[a]++;
	}
	int v=1;
	for (int i=2;i<=M;i++){
		int t=0;
		for (int j=1;i*j<=M;j++){
			t+=c[i*j];
		}
		v=max(v, t);
	}
	cout<<v<<endl;
}