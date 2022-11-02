#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int h[1010101];
int hi2[1010101];

vector<ll> a;
vector<ll> b;

void ans(int al, int ar, int bl, int br){
	cout<<ar-al+1<<endl;
	for (int i=al;i<=ar;i++){
		cout<<i+1<<" ";
	}
	cout<<endl<<br-bl+1<<endl;
	for (int i=bl;i<=br;i++){
		cout<<i+1<<" ";
	}
	cout<<endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	a.resize(n);
	b.resize(n);
	int sw=0;
	ll sa=0;
	ll sb=0;
	for (int i=0;i<n;i++){
		cin>>a[i];
		sa+=a[i];
	}
	for (int i=0;i<n;i++){
		cin>>b[i];
		sb+=b[i];
	}
	if (sa>sb){
		swap(a, b);
		sw=1;
	}
	ll s1=0;
	ll s2=0;
	int i2=0;
	for (int i=0;i<n;i++){
		s1+=(ll)a[i];
		while (i2<n&&s2+b[i2]<=s1){
			s2+=b[i2];
			i2++;
		}
		if (s1==s2){
			if (sw) ans(0, i2-1, 0, i);
			else ans(0, i, 0, i2-1);
		}
		if (h[s1-s2]){
			if (sw) ans(hi2[s1-s2], i2-1, h[s1-s2], i);
			else ans(h[s1-s2], i, hi2[s1-s2], i2-1);
		}
		h[s1-s2]=i+1;
		hi2[s1-s2]=i2;
	}
}