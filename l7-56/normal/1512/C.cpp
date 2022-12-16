#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int T,a[2],l,r;
string s;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &a[0], &a[1]);
		cin >> s;
		
		for(int i = 0; i < (int)s.size(); ++i){
			if(s[i] == '0') a[0]--;
			if(s[i] == '1') a[1]--;
		}
		if(a[0] < 0 || a[1] < 0) {printf("-1\n");continue;}
		
		for(l = 0, r = s.size() - 1; l < r; ++l, --r){
			if(s[l] == '?' && s[r] == '?') continue;
			if(s[l] == '?')
				s[l] = s[r], a[s[r] - '0']--;
			if(s[r] == '?')
				s[r] = s[l], a[s[l] - '0']--;
			if(s[l] != s[r]) a[0] = a[1] = -1;
		}
		
		for(l = 0, r = s.size() - 1; l < r; l++, r--)
			if(s[l] == '?' && s[r] == '?'){
				if(a[0] >= 2) s[l] = s[r] = '0', a[0] -= 2;
				else if(a[1] >= 2) s[l] = s[r] = '1', a[1] -= 2;
			}
		
		if((int)s.size() & 1){
			l = s.size() / 2;
			if(s[l] == '?'){
				if(a[0] > 0) s[l] = '0', a[0]--;
				else if(a[1] > 0) s[l] = '1', a[1]--;
			}
		}
		
		if(a[0] == 0 && a[1] == 0) cout << s << endl;
		else printf("-1\n");
	}
	
	return 0;
}