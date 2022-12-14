#include <cstdio>

char str[35], ans[5][35]; int pos[35];

int main(){
	int i, j, l, r;
	scanf("%s", str + 1);
	for(i = 1; i <= 27; ++ i){
		if(pos[str[i] - 'A']){
			if(str[i - 1] == str[i]){
				printf("Impossible\n");
				return 0;
			} break;
		} pos[str[i] - 'A'] = i;
	} l = pos[str[i] - 'A'], r = i;
	ans[2][j = 13 - (r - l - 1) / 2] = str[r];
	for(++ j, i = l + 1; i < r; ++ i){
		if(j > 13) -- j;
		if(ans[2][13]) ans[1][j --] = str[i];
		else ans[2][j ++] = str[i];
	}
	for(i = l - 1, j = 12 - (r - l - 1) / 2; i; -- i){
		if(!j) ++ j;
		if(ans[2][1]) ans[1][j ++] = str[i];
		else ans[2][j --] = str[i];
	}
	for(i = 27; i > r; -- i){
		if(!j) ++ j;
		if(ans[2][1]) ans[1][j ++] = str[i];
		else ans[2][j --] = str[i];
	} printf("%s\n%s\n", ans[1] + 1, ans[2] + 1);
	return 0;
}