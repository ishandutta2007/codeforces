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
	int e=-1;
	ll v=1;
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		if (a==1){
			if (e>-1){
				v*=(ll)(i-e);
			}
			e=i;
		}
	}
	if (e==-1){
		cout<<0<<endl;
	}
	else{
		cout<<v<<endl;
	}
}