#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

string ss;
string s[8];
int T,n,cnt;

int main(){
	scanf("%d", &T);
	while(T--){
		for(int i = 0; i < 8; ++i)
			s[i] = "";
		
		cin >> ss;
		n = ss.size(),cnt = 0;
		for(int i = 0; i < n;){
			while(i < n && ss[i] != ':') ++i;
			++cnt;
			while(i < n && ss[i] == ':') ++i;
		}
		
		for(int i = 0, t = 0; i < n;){
			while(i < n && ss[i] != ':') s[t] += ss[i++];
			if(i == n) break;
			if(++i < n && ss[i] == ':')
				t += 8 - cnt, ++i;
			++t;
		}
		
		for(int i = 0; i < 8; ++i)
			while(s[i].size() < 4) s[i] = '0' + s[i];
		
		cout << s[0];
		for(int i = 1; i < 8; ++i)
			cout << ":" << s[i];
		putchar('\n');
	}
	
	return 0;
}