#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
	ll c;
	while (a!=0){
		c=a;
		a=b%a;
		b=c;
	}
	return b;
}

ll a[1010101];


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	ll su=0;
	for (int i=0;i<n;i++){
		cin>>a[i];
		su+=a[i];
		su%=(ll)n;
	}
	std::mt19937 gen(su+31290);
	ll v=0;
	for (int q=0;q<10;q++){
		ll t=a[gen()%n];
		unordered_map<ll, int> g;
		for (int i=0;i<n;i++){
			g[gcd(t, a[i])]++;
		}
		for (auto i:g){
			int c=0;
			for (auto b:g){
				if (b.F%i.F==0) c+=b.S;
			}
			if (c>=n/2+n%2){
				v=max(v, i.F);
			}
		}
	}
	cout<<v<<endl;
}