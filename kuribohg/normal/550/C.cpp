#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char str[110];
int a[110],b[110],n,len;
void work(int x)
{
	if(x==0) {b[1]=0,len=1;return;}
	len=0;
	while(x)
	{
		b[++len]=x%10;
		x/=10;
	}
	reverse(b+1,b+len+1);
}
bool check()
{
	int cur=1;
	for(int i=0;i<n;i++)
	{
		if(cur==len+1) continue;
		if(a[i]==b[cur]) cur++;
	}
	if(cur==len+1) return true;
	return false;
}
void print(int b[])
{
	puts("YES");
	for(int i=1;i<=len;i++)
		putchar('0'+b[i]);
	puts("");
}
int main()
{
	scanf("%s",str);
	n=strlen(str);
	for(int i=0;i<n;i++) a[i]=str[i]-'0';
	for(int x=0;x<1000;x+=8)
	{
		//x=344;
		work(x);
		if(check()) {print(b);return 0;}
	}
	puts("NO");
	return 0;
}