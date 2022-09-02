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
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define pii Pi
#define pll PL
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> PL;

map <string, int> M;
char temp[50050];
int A[2][5050][1010];

void solve(){
	int n, m; scanf("%d %d\n", &n, &m);
	int C[5050][2] = {};
	M["?"] = -1;
	for(int i=1;i<=n;i++){
		gets(temp);
		vector <string> v;
		for(char *ch = strtok(temp, " "); ch; ch = strtok(NULL, " ")){
			v.pb((string(ch)));
		}
		M[v[0]] = i;
		if(sz(v) == 3){
			rep(j, m)A[1][i][j] = A[0][i][j] = v[2][j] - '0';
		}
		else{
			string op = v[3];
			int X = M[v[2]], Y = M[v[4]];
			rep(x, 2){
				rep(j, m){
					int xv;
					if(X == -1)xv = x;
					else xv = A[x][X][j];
					int yv;
					if(Y == -1)yv = x;
					else yv = A[x][Y][j];
					if(op == "AND")C[j][x] += A[x][i][j] = (xv & yv);
					if(op == "XOR")C[j][x] += A[x][i][j] = (xv ^ yv);
					if(op == "OR")C[j][x] += A[x][i][j] = (xv | yv);
				}
			}
		}
	}
	rep(i, m){
		if(C[i][0] <= C[i][1])printf("0");
		else printf("1");
	}
	puts("");
	rep(i, m){
		if(C[i][0] < C[i][1])printf("1");
		else printf("0");
	}
	puts("");
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		//printf("Case %d: ", tc);
		solve();
	}
	return 0;
}