#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

const int maxn = 2510;
int c[3],n,k;
string suf[4], kind[3] = {"aabb", "abab", "abba"};
bool vow(char ch){
	if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return 1;
	return 0;
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < 4; ++j){
			string s;
			cin >> s;
			int p = s.size() - 1, cnt = 0;
			while(p >= 0 && cnt < k) cnt += vow(s[p--]);
			if(p == -1 && cnt < k) return printf("NO"), 0;
			++p, suf[j] = s.substr(p, s.size() - p);
		}
		bool flag = 1;
		if(suf[0] == suf[1] && suf[2] == suf[3]) c[0]++, flag = 0;
		if(suf[0] == suf[2] && suf[1] == suf[3]) c[1]++, flag = 0;
		if(suf[0] == suf[3] && suf[1] == suf[2]) c[2]++, flag = 0;
		if(flag) return printf("NO"), 0;
	}
	if(c[0] == n && c[1] == n && c[2] == n) return printf("aaaa"), 0;
	for(int i = 0; i < 3; ++i)
		if(c[i] == n) {
			cout << kind[i] << endl;
			return 0;
		}
	printf("NO");
	
	return 0;
}
//CF138A