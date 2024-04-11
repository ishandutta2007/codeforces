#include <cstdio>
#include <cctype>

char s[100];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%s", s);
		bool type = 0;
		for(int i = 1; s[i]; ++i){
			if(!isdigit(s[i]) && isdigit(s[i - 1])){
				type = 1;
				break;
			}
		}
		if(type == 0){
			int c = 0;
			int j;
			for(j = 0; !isdigit(s[j]); ++j){
				c = 26 * c + s[j] - 'A' + 1;
			}
			int r = 0;
			for(; s[j]; ++j){
				r = 10 * r + s[j] - '0';
			}
			printf("R%dC%d\n", r, c);
		}else{
			int r = 0;
			int j;
			for(j = 1; isdigit(s[j]); ++j){
				r = 10 * r + s[j] - '0';
			}
			int c = 0;
			for(++j; s[j]; ++j){
				c = 10 * c + s[j] - '0';
			}
			int z = 0;
			while(c){
				s[z++] = c % 26 + 'A' - 1;
				if(s[z - 1] < 'A'){
					s[z - 1] = 'Z';
					c -= 26;
				}
				c /= 26;
			}
			for(int k = z - 1; k >= 0; --k) putchar(s[k]);
			printf("%d\n", r);
		}
	}
}