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

bitset<26> pos;
int n;
char s[100005];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < 26; ++i)
		pos[i] = 1;
	bool flag = 0;
	int cnt = 0;
	for(int t = 0; t < n; ++t){
		scanf("%s", s);
		if(s[0] == '.'){
			scanf("%s", s);
			for(int i = 0; s[i]; ++i)
				pos[s[i] - 'a'] = 0;
			if(pos.count() == 1) flag = 1;
		}else if(s[0] == '!'){
			scanf("%s", s);
			if(flag) ++cnt;
			bitset<26> can = 0;
			for(int i = 0; s[i]; ++i)
				can[s[i] - 'a'] = 1;
			pos &= can;
			if(pos.count() == 1) flag = 1;
		}else if(s[0] == '?'){
			scanf("%s", s);
			if(flag && !pos[s[0] - 'a']) ++cnt;
			pos[s[0] - 'a'] = 0;
			if(pos.count() == 1) flag = 1;
		}
	}
	printf("%d\n", cnt);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}