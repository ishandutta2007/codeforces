#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, m, k, a, b;
set<pair<int,int> > non;
queue<int> unused;
int cc[300000];
int cur[300000];
int idx = 0;
int main(){
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		cc[i] = -1;
		if(i > 0) unused.push(i);
		non.insert(make_pair(i,i));
	}
	int deg1 = n-1;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		if(a == 1 || b == 1) deg1--;
		non.insert(make_pair(a-1,b-1));
		non.insert(make_pair(b-1,a-1));
	}
	if(deg1 < k){
		cout << "impossible" << endl;
		return 0;
	}
	int ncc = 0;
	for(int l = 1; l < n; l++){
		if(cc[l] == -1){
			ncc++;
			if(ncc > k){
				cout << "impossible" << endl;
				return 0;
			}
			idx = 0;
			cc[l] = l;
			cur[idx++] = l;
			int steps = 0;
			while(unused.size() > 0){
				steps++;
				a = unused.front();
				unused.pop();
				if(cc[a] >= 0) continue;
				for(int j = idx-1; j >= 0; j--){
					if(non.find(make_pair(cur[j],a))==non.end()){
						cc[a] = l;
						cur[idx++] = a;
						steps = 0;
						break;
					}
				}
				if(steps == 0) continue;
				unused.push(a);
				if(steps > unused.size() + 10){
					break;
				}
			}
			int y = 0;
			for(int i = 0; i < idx; i++){
				if(non.find(make_pair(0,cur[i])) == non.end()){
					y++;
				}
			}
			if(y == 0){
				cout << "impossible" << endl;
				return 0;
			}
		}
	}
	if(ncc > k){
		cout << "impossible" << endl;
		return 0;
	}
	cout << "possible" << endl;
	return 0;

}