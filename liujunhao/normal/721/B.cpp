#include<cstdio>
#include<algorithm>
#include<cstring>
char s[200];
int n,k,cnt[200];
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
int cal(int n){
	return (n-1)/k*5+n;
}
int main()
{
	Read(n),Read(k);
	int i,len;
	for(i=1;i<=n;i++){
		scanf("%s",s);
		cnt[strlen(s)]++;
	}
	scanf("%s",s);
	len=strlen(s);
	for(i=1;i<=len;i++)
		cnt[i]+=cnt[i-1];
	printf("%d %d\n",cal(cnt[len-1]+1),cal(cnt[len]));
}