#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

multiset<pair<ll, int> > cs[10];

ll p[202020];
int a[202020];
int b[202020];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>p[i];
	}
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		cin>>b[i];
		cs[a[i]].insert({p[i], i});
		cs[b[i]].insert({p[i], i});
	}
	int m;
	cin>>m;
	for (int i=0;i<m;i++){
		int c;
		cin>>c;
		if (cs[c].size()==0){
			cout<<"-1 ";
		}
		else{
			auto t=*cs[c].begin();
			cout<<t.F<<" ";
			int d=t.S;
			cs[a[d]].erase(cs[a[d]].find({p[d], d}));
			cs[b[d]].erase(cs[b[d]].find({p[d], d}));
		}
	}
	cout<<endl;
}