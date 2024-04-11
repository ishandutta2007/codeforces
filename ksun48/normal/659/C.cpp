#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int used[2000000];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < 2000000; i++){
		used[i] = 0;
	}
	vector<int> c;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;

		if(a < 2000000) used[a] = 1;
	}
	for(int i = 1; i < 2000000; i++){
		if(i <= m){
			if(used[i] == 0){
				m -= i;
				c.push_back(i);
			}
		}
	}
	cout << c.size() << endl;
	for(int i = 0; i < c.size(); i++){
		printf("%d ", c[i]);
	}
	cout << endl;
}