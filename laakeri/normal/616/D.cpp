#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int c[1010101];
int a[1010101];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pair<int, pair<int, int> > ma={0, {0, 0}};
	int n,k;
	cin>>n>>k;
	int dv=0;
	int i2=0;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		if (c[a[i]]==0){
			dv++;
		}
		c[a[i]]++;
		while (dv>k){
			if (c[a[i2]]==1) dv--;
			c[a[i2]]--;
			i2++;
		}
		ma=max(ma, {i-i2, {i2+1, i+1}});
	}
	cout<<ma.S.F<<" "<<ma.S.S<<endl;
}