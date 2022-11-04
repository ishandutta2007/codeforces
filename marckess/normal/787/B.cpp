#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
#define ll long long
#define vi vector<bool>

using namespace std;

int main(){
	ll n, m, k, x;
	cin >> n >> m;
	bool res = false;

	while(m--){
		res = false;
		vi r(n+5,false), m(n+5,false);
		cin>> k;
		while(k--){
			cin>>x;
			if(x>0)
				m[x]=true;
			else
				r[-x]=true;
		}
		for(int i = 1; i<=n; i++ )
			if(m[i] and r[i]){
				res = true;
			}
		if(!res)
			break;
	}

	if(res)
		cout << "NO";
	else
		cout << "YES";

	return 0;
}