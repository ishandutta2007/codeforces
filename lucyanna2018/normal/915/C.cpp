#include<cstdio>
#include<cstring>
int la,lb;
char a[22],b[22],c[22];
int cnt[10];
int main(){
	scanf("%s%s",a,b);
	for(int i=0; a[i]; i++)
		cnt[a[i]-'0']++;
	la = strlen(a);
	lb = strlen(b);
	if(la < lb){
		for(int i=9; i>=0; i--)
			while(cnt[i]--)
				putchar(i+'0');
		puts("");
		return 0;
	}
	for(int i=0; i<lb; i++){
		for(int d=9; d>=0; d--)if(cnt[d] > 0){
			c[i] = d + '0';
			cnt[d] --;
			int lc = i+1;
			for(int d2=0; d2<=9; d2++)
				for(int j=0; j<cnt[d2]; j++)
					c[lc++] = d2+'0';
			if(memcmp(c,b,sizeof(char)*lc) <= 0)
				break;
			cnt[d] ++;
		}
	}
	c[la] = 0;
	puts(c);
	return 0;
}