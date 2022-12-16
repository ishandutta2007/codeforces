#include<bits/stdc++.h>
using namespace std;

const int maxn = 60;
int t,cnt[30];
char ch[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		memset(cnt, 0, sizeof cnt);
		cin >> ch;
		int l = strlen(ch);
		for(int i = 0; i < l; ++i)
			cnt[ch[i] - 'a']++;
		int cnt1 = 0, cnt2 = 0;
		for(int i = 0; i < 26; ++i){
			if(cnt[i] >= 2) cnt2++;
			if(cnt[i] == 1) cnt1++;
		}
		printf("%d\n", cnt2 + cnt1 / 2);
	}
	return 0;
}