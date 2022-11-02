#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

map<int, int> co;
int b[202020];
int c[202020];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		co[a]++;
	}
	pair<pair<int, int>, int> v={{-1, -1}, -1};
	int m;
	cin>>m;
	for (int i=0;i<m;i++){
		cin>>b[i];
	}
	for (int i=0;i<m;i++){
		cin>>c[i];
	}
	for (int i=0;i<m;i++){
		v=max(v, {{co[b[i]], co[c[i]]}, i+1});
	}
	cout<<v.S<<endl;
}