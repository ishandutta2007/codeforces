#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef unsigned long long ll;

map<ll, int> c;

ll p=1238931287;
ll k=3813312933;

ll co=34434277;

ll dfs(string&s, int a, int b, int t){
	if ((b-a+1)%2==1){
		ll h=co;
		for (int i=a;i<=b;i++){
			h+=(ll)s[i];
			h*=p;
		}
		//cout<<s<<" 1 "<<h<<endl;
		c[h]+=t;
		return h;
	}
	else{
		int m=(a+b)/2;
		ll l=dfs(s, a, m, t);
		ll r=dfs(s, m+1, b, t);
		if (l<r) swap(l, r);
		ll h=(l+k)*r;
		//cout<<s<<" 2 "<<h<<endl;
		c[h]+=t;
		return h;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s1,s2;
	cin>>s1>>s2;
	dfs(s1, 0, (int)s1.size()-1, 1);
	dfs(s2, 0, (int)s2.size()-1, -1);
	for (auto t:c){
		if (t.S>0){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
}