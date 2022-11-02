#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin>>q;
	map<int, int> cnt;
	for (int qq=0;qq<q;qq++){
		char t;
		string a;
		cin>>t>>a;
		int v=0;
		int p=1;
		for (int i=(int)a.size()-1;i>=0;i--){
			if ((a[i]-'0')%2==1) v+=p;
			p*=2;
		}
		if (t=='+') cnt[v]++;
		if (t=='-') cnt[v]--;
		if (t=='?') cout<<cnt[v]<<"\n";
	}
}