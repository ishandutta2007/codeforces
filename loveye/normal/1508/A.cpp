#include<bits/stdc++.h>
using namespace std;
int t,n;
string s1,s2,s3;
int main() {
	cin >> t;
	while(t--) {
		cin >> n;
		cin >> s1 >> s2 >> s3;
		int cnt1 = 0,cnt2 = 0,cnt3 = 0;
		for(int i = 0;i < 2*n;++i)
			if(s1[i] == '1') ++cnt1;
		for(int i = 0;i < 2*n;++i)
			if(s2[i] == '1') ++cnt2;
		for(int i = 0;i < 2*n;++i)
			if(s3[i] == '1') ++cnt3;
			
		if((cnt1 >= n) + (cnt2 >= n) + (cnt3 >= n) >= 2) {
			if(!(cnt1 >= n)) swap(s1,s3),swap(cnt1,cnt3);
			else if(!(cnt2 >= n)) swap(s2,s3),swap(cnt2,cnt3);
			if(cnt1 < cnt2) swap(s1,s2);
			int p = 0;
			cnt1 = n;
			for(int i = 0;i < 2*n;++i) {
				if(s1[i] == '1' && cnt1 > 0) {
					--cnt1;
					while(p < s2.length() && s2[p] == '0') putchar('0'),++p;
					++p;
				}
				putchar(s1[i]);
				if(cnt1 == 0) {
					--cnt1;
					while(p < s2.length()) putchar(s2[p]),++p;
				}
			}
			putchar('\n');
		} else {
			if((cnt1 > n)) swap(s1,s3),swap(cnt1,cnt3);
			else if((cnt2 > n)) swap(s2,s3),swap(cnt2,cnt3);
			if(cnt1 > cnt2) swap(s1,s2);
			int p = 0;
			cnt1 = n;
			for(int i = 0;i < 2*n;++i) {
				if(s1[i] == '0' && cnt1 > 0) {
					--cnt1;
					while(p < s2.length() && s2[p] == '1') putchar('1'),++p;
					++p;
				}
				putchar(s1[i]);
				if(cnt1 == 0) {
					--cnt1;
					while(p < s2.length()) putchar(s2[p]),++p;
				}
			}
			putchar('\n');
		}
	}
	return 0;
}