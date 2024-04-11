#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()
typedef long long ll;

char s[5005];
int cnt[5005][26];
int f[5005];

int main(){
	scanf("%s", s);
	int n = strlen(s), ans = 0;
	for(char c = 'a'; c <= 'z'; ++c){
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < n; ++i){
			if(s[i] == c){
				for(int j = 0; j < n; ++j){
					++cnt[j][s[(i + j) % n] -'a'];
				}
			}
		}
		memset(f, 0, sizeof(f));
		for(int i = 0; i < n; ++i){
			if(s[i] == c){
				for(int j = 0; j < n; ++j)
					if(cnt[j][s[(i + j) % n] - 'a'] == 1)
						++f[j];
			}
		}
		int mx = 0;
		for(int i = 0; i < n; ++i)
			mx = max(mx, f[i]);
		ans += mx;
	}
	printf("%.10f\n", 1. * ans / n);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}