#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define c 3533
#define MOD 1000000009

set<int> s[300000];
char str[310000];
int cnt[310000];
LL powc[310000];
multiset<int> check;
int main(){
	int m;
	scanf("%d", &m);
	powc[0] = 1;
	for(int i = 1; i < 310000; i++){
		powc[i] = (c*powc[i-1]) % MOD;
	}
	for(int i = 0; i < 310000; i++) cnt[i] = 0;
	for(int i = 0; i < m; i++){
		int t;
		scanf("%d%s", &t, str);
		int d = strlen(str);
		if(t != 3){
			LL r = 0;
			for(int i = 0; i < d; i++){
				r *= c;
				r += (str[i]-'a'+1);
				r %= MOD;
			}
			if(t == 1){
				s[d].insert(r);
				if(cnt[d] == 0) check.insert(d);
				cnt[d]++;
				//cout << "+" << r << endl;
			}
			if(t == 2){
				s[d].erase(r);
				cnt[d]--;
				if(cnt[d] == 0) check.erase(d);
				//cout << "-" << r << endl;
			}
		} else if(t == 3){
			LL ans = 0;
			for(multiset<int>::iterator a = check.begin(); a != check.end(); a++){
				int l = *a;
				if(l > d){
					break;
				}
				LL r = 0;
				for(int i = 0; i < l; i++){
					r *= c;
					r += (str[i]-'a'+1);
					r %= MOD;
				}
				ans += s[l].count(r);
				//cout << "c" << r << endl;
				for(int i = l; i < d; i++){
					r *= c;
					r -= powc[l]*(str[i-l]-'a'+1);
					r += (str[i]-'a'+1);
					r %= MOD;
					while(r < 0) r += MOD;
					ans += s[l].count(r);
					//cout << "c" << r << endl;
				}

			}
			printf("%I64d\n", ans);
			fflush(stdout);
		}
	}
}