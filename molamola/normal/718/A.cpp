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

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

int n, t;
char ch[200020];

void Do(int x){
	vector <int> v;
	for(int i=x;i>=0;i--)v.pb(ch[i] - '0');
	v.pb(0);
	for(int i=0;;i++){
		if(v[i] != 10)break;
		v[i+1]++;
		v[i] = 0;
	}
	if(v.back() == 0)v.pop_back();
	reverse(all(v));
	for(auto e : v)printf("%d", e);
}

void solve(int tc){
	scanf("%d%d", &n, &t);
	scanf("%s", ch);
	for(int i=0;i<n;i++){
		if(ch[i] == '.'){
			for(int j=i+1;j<n;j++){
				if(ch[j] >= '5'){
					ch[j] = 0;
					if(ch[j-1] == '.'){
						ch[j-2]++;
						Do(j-2);
						return;
					}
					else{
						ch[j-1]++;
						for(int k=1;k<t;k++){
							if(ch[j-k] != '5')break;
							if(ch[j-k-1] == '.'){
								ch[j-k-2]++;
								Do(j-k-2);
								return;
							}
							ch[j-k] = 0;
							ch[j-k-1]++;
						}
					}
					break;
				}
			}
			break;
		}
	}
	printf("%s\n", ch);
}

int main(){
	int Tc = 1;//; scanf("%d\n", &Tc);
	for(int tc=1; tc<=Tc; tc++){
		solve(tc);
	}
	return 0;
}