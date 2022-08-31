#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	string l;
	cin >> l;
	multiset<pair<int,int> > r;
	int a = 0;
	int b = 0;
	r.insert(make_pair(a,b));
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(l[i] == 'U'){
			a++;
		} else if(l[i] == 'D'){
			a--;
		} else if(l[i] == 'L'){
			b++;
		} else if(l[i] == 'R'){
			b--;
		}
		ans += r.count(make_pair(a,b));
		r.insert(make_pair(a,b));
	}
	cout << ans << endl;
}