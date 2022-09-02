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

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

char ch[100010];

void solve(int tc){
	scanf("%s", ch);
	int L = (int)strlen(ch);
	int ok = 0;
	for(int i=0;i<L;i++){
		if(ch[i] != 'a')ok = 1;
	}
	if(!ok){
		ch[L-1] = 'z';
		printf("%s", ch);
		return;
	}
	if(ch[0] == 'a'){
		for(int i=1;i<L;i++)if(ch[i] != 'a'){
			for(int j=i;j<L;j++){
				if(ch[j] != 'a')ch[j]--;
				else break;
			}
			break;
		}
		printf("%s", ch);
	}
	else{
		for(int i=0;i<L;i++){
			if(ch[i] == 'a')break;
			ch[i]--;
		}
		printf("%s", ch);
	}
}

int main(){
	int Tc = 1;//; scanf("%d", &Tc);
	for(int tc=1; tc<=Tc; tc++){
		solve(tc);
	}
	return 0;
}