#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 100000
using namespace std;
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
int n,k,ans;
char s[MAXN+10];
int main()
{
	Read(n),Read(k);
	scanf("%s",s+1);
	int i=0,j=0,cnt=0;
	while(i<=n&&j<=n){
		while(cnt<=k&&j<=n){
			j++;
			if(s[j]=='b')
				cnt++;
		}
		ans=max(ans,j-i-1);
		while(cnt>k&&i<=n){
			i++;
			if(s[i]=='b')
				cnt--;
		}
	}
	i=0,j=0,cnt=0;
	while(i<=n&&j<=n){
		while(cnt<=k&&j<=n){
			j++;
			if(s[j]=='a')
				cnt++;
		}
		ans=max(ans,j-i-1);
		while(cnt>k&&i<=n){
			i++;
			if(s[i]=='a')
				cnt--;
		}
	}
	printf("%d\n",ans);
}