#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	string g[10];
	for(int i = 0; i < 10; i++){
		cin >> g[i];
	}
	int dx[8] = {1,0,-1,0,1,-1,1,-1};
	int dy[8] = {0,1,0,-1,1,-1,-1,1};
	int ok = 0;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			for(int c = 0; c < 8; c++){
				if(i + 4*dx[c] < 0 || i + 4*dx[c] >= 10) continue;
				if(j + 4*dy[c] < 0 || j + 4*dy[c] >= 10) continue;
				int works = 1;
				int numblank = 0;
				for(int z = 0; z <= 4; z++){
					if(g[i+z*dx[c]][j+z*dy[c]] == 'O'){
						works = 0;
						numblank++;
					} else if(g[i+z*dx[c]][j+z*dy[c]] == '.'){
						numblank++;
					}
				}
				if((numblank <= 1) && works) ok = 1;
			}
		}
	}
	cout << (ok ? "YES" : "NO") << endl;
}