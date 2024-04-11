#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

const int N=1<<18;
int st[2*N];
void add(int i, int x){
	for (i+=N;i;i/=2){
		st[i]+=x;
	}
}
int sum(int a, int b){
	a+=N;
	b+=N;
	int s=0;
	while (a<=b){
		if (a%2) s+=st[a++];
		if (!(b%2)) s+=st[b--];
		a/=2;
		b/=2;
	}
	return s;
}

int a[202020];
int p[202020];
vector<int> d[202020];
vector<pair<int, int> > qq[202020];
int v[202020];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
		p[a[i]]=i;
	}
	for (int i=1;i<=n;i++){
		for (int j=2;j*i<=n;j++){
			d[j*i].push_back(i);
		}
	}
	for (int i=0;i<m;i++){
		int aa,bb;
		cin>>aa>>bb;
		qq[bb-1].push_back({aa-1, i});
	}
	for (int i=0;i<n;i++){
		for (int k=1;k*a[i]<=n;k++){
			if (p[k*a[i]]<=i){
				add(p[k*a[i]], 1);
			}
		}
		for (int dd:d[a[i]]){
			if (p[dd]<=i){
				add(p[dd], 1);
			}
		}
		for (auto q:qq[i]){
			v[q.S]=sum(q.F, i);
		}
	}
	for (int i=0;i<m;i++){
		cout<<v[i]<<'\n';
	}
}