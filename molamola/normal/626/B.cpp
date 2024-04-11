#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <time.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()

int d[205][205][205];

int dfs(int a,int b,int c){
	if(d[a][b][c] != -1)return d[a][b][c];
	if(a < 0 || b < 0 || c < 0)return 0;
	if(a == 0 && b == 0)return 4;
	if(b == 0 && c == 0)return 1;
	if(a == 0 && c == 0)return 2;
	int res = 0;
	if(a >= 2)res |= dfs(a-1, b, c);
	if(b >= 2)res |= dfs(a, b-1, c);
	if(c >= 2)res |= dfs(a, b, c-1);
	if(a && b)res |= dfs(a-1, b-1, c+1);
	if(b && c)res |= dfs(a+1, b-1, c-1);
	if(c && a)res |= dfs(a-1, b+1, c-1);
	return d[a][b][c] = res;
}

int main(){
	memset(d, -1, sizeof d);
	int n;
	char ch[220];
	scanf("%d%s", &n, ch);
	int a, b, c;
	a = b = c = 0;
	for(int i=0;i<n;i++){
		if(ch[i] == 'B')a++;
		if(ch[i] == 'G')b++;
		if(ch[i] == 'R')c++;
	}
	int x = dfs(a, b, c);
	if(x & 1)printf("B");
	if(x & 2)printf("G");
	if(x & 4)printf("R");
	return 0;
}