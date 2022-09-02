#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <list>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

int p[130] = {};

void solve(){
	char S[30];
	scanf("%s", S);
	memset(p, -1, sizeof p);
	int s, e; char x;
	for(int i=0;i<27;i++){
		if(p[S[i]] != -1){
			s = p[S[i]], e = i, x = S[i];
		}
		p[S[i]] = i;
	}
	if(e - s == 1){
		puts("Impossible");
		return;
	}
	if((e - s) % 2 == 1){
		int t = (e - s) / 2;
		char ans[2][20] = {};
		int a = 12 - (e - s) / 2;
		ans[1][a] = x;
		int dx = 0, dy = a + 1;
		for(int i=s+1;i<e;i++){
			ans[dx][dy] = S[i];
			if(dx == 0)dy++;
			else dy--;
			if(dy == 13){
				dy = 12; dx = 1;
			}
		}
		dx = 0, dy = a;
		for(int i=e+1;i<27;i++){
			ans[dx][dy] = S[i];
			if(dx == 0)dy--;
			else dy++;
			if(dy == -1){
				dy = 0; dx = 1;
			}
		}
		dx = 1, dy = a-1;
		if(dy == -1)dy = 0, dx = 0;
		for(int i=s-1;i>=0;i--){
			ans[dx][dy] = S[i];
			if(dx == 0)dy++;
			else dy--;
			if(dy == -1){
				dx = 0;
				dy = 0;
			}
		}
		printf("%s\n%s", ans[0], ans[1]);
	}
	else{
		int t = (e - s) / 2 - 1;
		char ans[2][20] = {};
		int a = 13 - (e - s) / 2;
		ans[1][a] = x;
		int dx = 0, dy = a;
		for(int i=s+1;i<e;i++){
			ans[dx][dy] = S[i];
			if(dx == 0)dy++;
			else dy--;
			if(dy == 13){
				dy = 12; dx = 1;
			}
		}
		dx = 0, dy = a - 1;
		for(int i=e+1;i<27;i++){
			ans[dx][dy] = S[i];
			if(dx == 0)dy--;
			else dy++;
			if(dy == -1){
				dy = 0; dx = 1;
			}
		}
		dx = 1, dy = a-1;
		if(dy == -1)dy = 0, dx = 0;
		for(int i=s-1;i>=0;i--){
			ans[dx][dy] = S[i];
			if(dx == 0)dy++;
			else dy--;
			if(dy == -1){
				dx = 0;
				dy = 0;
			}
		}
		printf("%s\n%s", ans[0], ans[1]);
	}
}
int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}