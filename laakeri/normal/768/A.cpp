#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int a[101010];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int mi=1e9+1;
	int ma=0;
	for (int i=0;i<n;i++){
		cin>>a[i];
		mi=min(mi, a[i]);
		ma=max(ma, a[i]);
	}
	int v=0;
	for (int i=0;i<n;i++){
		if (a[i]>mi&&a[i]<ma) v++;
	}
	cout<<v<<endl;
}