#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int a[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[x]=i;
	}
	set<int> p;
	int i2=1;
	int mv=n;
	for (int i=1;i<=n;i++){
		while ((int)p.size()>0&&(*p.rbegin())>a[i]){
			p.erase(a[i2]);
			i2++;
		}
		p.insert(a[i]);
		mv=min(mv, n-(int)p.size());
	}
	cout<<mv<<endl;
}