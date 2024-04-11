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
typedef long double ldouble;

char S[100010];

string res;

void solve(){
	scanf("%s", S+1);
	int n = (int)strlen(S+1);
	int sum = 0;
	for(int i=1;i<=n;i++)sum += S[i] - '0';
	sum %= 3;
	if(sum == 0)printf("%s\n", S+1);
	else{
		if(n == 1){puts("-1");return;}
		for(int i=n;i;i--){
			int c = (S[i] - '0') % 3;
			if(c == sum){
				string temp;
				for(int j=1;j<=n;j++)if(j != i)temp += S[j];
				reverse(all(temp));
				while(sz(temp) > 1 && temp.back() == '0')temp.pop_back();
				reverse(all(temp));
				if(sz(temp))res = temp;
				break;
			}
		}
		vector <int> v;
		for(int i=n;i;i--){
			int c = (S[i] - '0') % 3;
			if(c + sum == 3){
				v.pb(i);
				if(sz(v) == 2)break;
			}
		}
		if(sz(v) >= 2){
			string temp;
			for(int i=1;i<=n;i++)if(i != v[0] && i != v[1])temp.pb(S[i]);
			reverse(all(temp));
			
			while(sz(temp) > 1 && temp.back() == '0')temp.pop_back();
			reverse(all(temp));
			if(sz(temp) && (res == "" || sz(temp) > sz(res)))res = temp;
		}
		if(sz(res) == 0)puts("-1");
		else printf("%s\n", res.c_str());
	}
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}