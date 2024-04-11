#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int stuff[200][1000];
int sz[200];

int main(){
	int n, time;
	cin >> n >> time;
	int depth[n];
	int val[n];
	for(int i = 0; i < n; i++){
		cin >> depth[i] >> val[i];
		depth[i] = time-depth[i];
	}
	for(int i = 0; i < 200; i++){
		sz[i] = 0;
	}
	for(int i = 0; i < n; i++){
		stuff[depth[i]][sz[depth[i]]++] = -val[i];
	}
	for(int i = 150; i>= 1; i--){
		sort(stuff[i], stuff[i]+sz[i]);
		for(int c = 0; c < sz[i]; c += 2){
			if(c+1 == sz[i]){
				stuff[i-1][sz[i-1]++] = stuff[i][c];

			} else {
				stuff[i-1][sz[i-1]++] = stuff[i][c]+stuff[i][c+1];
			}
		}
	}
	sort(stuff[0], stuff[0]+sz[0]);
	cout << -stuff[0][0] << endl;
}