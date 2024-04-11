#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
struct data
{
	int id;
	int len;
}a[7];
char s[105];
int cmp(data x,data y)
{
	return x.len<y.len;
}
int main()
{
	scanf("%s",s+1);
	a[1].len=strlen(s+1)-2;
	scanf("%s",s+1);
	a[2].len=strlen(s+1)-2;
	scanf("%s",s+1);
	a[3].len=strlen(s+1)-2;
	scanf("%s",s+1);
	a[4].len=strlen(s+1)-2;
	
	for(int i=1;i<=4;i++)
	a[i].id=i;
	sort(a+1,a+5,cmp);
	//cout<<a[1].len<<" "<<a[2].len<<" "<<a[3].len<<" "<<a[4].len<<endl;
	if(a[4].len>=2*a[3].len&&a[2].len<2*a[1].len)
	{
		printf("%c",a[4].id+'A'-1);
	}
	else if(a[4].len<2*a[3].len&&a[2].len>=2*a[1].len)
	{
		printf("%c",a[1].id+'A'-1);
	}
	else printf("C");
}