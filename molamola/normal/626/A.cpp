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

int n;
char ch[220];

int main(){
	scanf("%d", &n);
	scanf("%s", ch);
	int ans = 0;
	rep(i, n){
		rep(j, i+1){
			//[j, i]
			int a = 0, b = 0;
			for(int k=j;k<=i;k++){
				if(ch[k] == 'L')a++;
				if(ch[k] == 'R')a--;
				if(ch[k] == 'U')b++;
				if(ch[k] == 'D')b--;
			}
			if(a == 0 && b == 0)ans++;
		}
	}
	printf("%d", ans);
	return 0;
}