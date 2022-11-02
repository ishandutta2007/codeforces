#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n);
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(), a.end());
	int t1=(n-2)/2+(n-2)%2;
	int v=a[n-1]-a[0];
	for (int i=0;i<=t1;i++){
		v=min(v, a[n-t1+i-1]-a[i]);
	}
	cout<<v<<endl;
}