#include<stdio.h>
#include<ctype.h>
int max_line;
char ch[1111111];
bool good(char x){
	if(x == ' ')return true;
	if(x == '-')return true;
	if(isalpha(x))return true;
	return false;
}
bool chk(int mx){
	int line = 1, cur = 0, prev = 0;
	for(int i=0; good(ch[i]); i++){
		cur++;
		if(ch[i] == ' ' || ch[i] == '-' || !good(ch[i+1])){
			if(cur - prev > mx)return false;
			if(cur > mx){
				line++;
				int L = cur - prev;
				prev = cur = L;
			}else
				prev = cur;
		}
	}
	return line <= max_line;
}
int main(){
	scanf("%d%*c",&max_line);
	fgets(ch,1<<20,stdin);
	int lo = 1, hi = 1000000;
	while(lo != hi){
		int mi = (lo + hi)/2;
		if(chk(mi))
			hi = mi;
		else
			lo = mi+1;
	}
	printf("%d\n",lo);
	return 0;
}