#include<iostream>
#include<cstdio>

using namespace std;

int n;

inline void to26(int c){
	if(c <= 26) {
		putchar('A' + c - 1);
		return;
	}
	if(c % 26 == 0){
		to26(c / 26 - 1);
		putchar('Z');
		return;
	}
	to26(c / 26);
	putchar('A' + c % 26 - 1);
	return;
}

bool check(string s){
	int cnt = 0;
	for(int i = 0; i < (int)s.size(); ++i)
		cnt += isalpha(s[i]);
	if(cnt == 2 && isdigit(s[1])) return 1;
	return 0;
}

int main(){
	scanf("%d", &n);
	while(n--){
		string s;
		cin >> s;
		if(check(s)){
			int i,r,c;
			i = r = c = 0;
			while(!isdigit(s[i])) ++i;
			while(isdigit(s[i])) r = (r << 1) + (r << 3) + s[i] - '0', ++i;
			while(!isdigit(s[i])) ++i;
			while(isdigit(s[i])) c = (c << 1) + (c << 3) + s[i] - '0', ++i;
			to26(c);printf("%d\n", r);
		}
		else {
			int i,r,c;
			i = r = c = 0;
			while(s[i] <= 'Z' && s[i] >= 'A') c = c * 26 + s[i] - 'A' + 1, ++i;
			while(isdigit(s[i])) r = r * 10 + s[i] - '0', ++i;
			printf("R%dC%d\n", r, c);
		}
	}
	return 0;
}