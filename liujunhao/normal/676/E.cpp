#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 100000
using namespace std;
int n,k,a[MAXN+10],cnt;
char s[20];
void Read(int &x){
	char c;
	bool f=0;
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
int main()
{
	Read(n),Read(k);
	int i,j;
	for(i=0;i<=n;i++){
		scanf("%s",s);
		if(*s=='?'){
			cnt++;
			a[i]=-10000000;
		}
		else{
			if(s[0]=='-')
				j=1;
			else
				j=0;
			for(;s[j];j++){
				a[i]=a[i]*10+s[j]-'0';
			}
			if(s[0]=='-')
				a[i]=-a[i];
		}
	}
	if(k==0){
		if(a[0]==-10000000){
			if((n+1-cnt)&1)
				puts("Yes");
			else
				puts("No");
		}
		else if(a[0])
			puts("No");
		else
			puts("Yes");
	}
	else{
		if(!cnt){
			for(i=n;i>=0;i--){
				a[i]=a[i+1]*k+a[i];
				if(abs(a[i])>=100000){
					puts("No");
					break;
				}
			}
			if(i==-1){
				if(!a[0])
					puts("Yes");
				else
					puts("No");
			}
		}
		else{
			if((n+1)&1)
				puts("No");
			else
				puts("Yes");
		}
	}
}