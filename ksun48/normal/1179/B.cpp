#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pair<int,int> > z;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			z.emplace_back(i+1, j+1);
		}
	}
	int s = 0;
	int e = (int)z.size();
	int b = 0;
	while(s < e){
		int a;
		if(b == 0){
			a = s;
			s += 1;
		} else {
			e -= 1;
			a = e;
		}
		b ^= 1;
		cout << z[a].first << " " << z[a].second << '\n';
	}
}