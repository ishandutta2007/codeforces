#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL ok[2500];
vector<int> f;
vector<int> g;
int s = 0;
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	int stuff[4000];
	for(int i = 0; i < 4000; i++){
		stuff[i] = 0;
	}
	int a;
	for(int i = 0; i < k; i++){
		scanf("%d", &a);
		stuff[a] = 1;
	}
	for(int i = 0; i < 4000; i++){
		if(stuff[i]){
			f.push_back(i-n);
		}
	}
	for(int i = 0; i < 2500; i++){
		ok[i] = -1;
	}
	for(int i = 0; i < f.size(); i++){
		if(f[i] >= 0 && f[i] < 2500){
			g.push_back(f[i]);
			ok[f[i]] = 1;
		}
	}
	while(s < g.size()){
		for(int i = 0; i < f.size(); i++){
			int r = f[i] + g[s];
			if(r >= 0 && r < 2500 && ok[r] == -1){
				ok[r] = ok[g[s]] + 1;
				g.push_back(r);
			}
		}
		s++;
	}
	cout << ok[0] << endl;
}