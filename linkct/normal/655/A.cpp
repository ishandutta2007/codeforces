#include <cstdio>

int main(){
	char s[10], s2[10], x; int i;
	scanf("%s%s%s%s", s + 1, s + 3, s2 + 1, s2 + 3);
	x = s[3], s[3] = s[4], s[4] = x;
	x = s2[3], s2[3] = s2[4], s2[4] = x;
	while(s[1] != 'X'){
		for(x = s[1], i = 2; i <= 4; ++ i)
			s[i - 1] = s[i];
		s[4] = x;
	}
	while(s[2] != 'A'){
		for(x = s[2], i = 3; i <= 4; ++ i)
			s[i - 1] = s[i];
		s[4] = x;
	}
	while(s2[1] != 'X'){
		for(x = s2[1], i = 2; i <= 4; ++ i)
			s2[i - 1] = s2[i];
		s2[4] = x;
	}
	while(s2[2] != 'A'){
		for(x = s2[2], i = 3; i <= 4; ++ i)
			s2[i - 1] = s2[i];
		s2[4] = x;
	}
	for(i = 1; i <= 4; ++ i) if(s[i] != s2[i]) break;
	printf("%s\n", i <= 4 ? "NO" : "YES");
	return 0;
}