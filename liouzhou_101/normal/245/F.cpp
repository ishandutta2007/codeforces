#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>

using namespace std;

int days[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

queue<long long> Q;
int n,m;
char s[10000100];

int main()
{
	cin>>n>>m;
	int tot=0;
	while (scanf("%s",s)!=EOF)
	{
		++tot;
		long long now=0;
		int MMM=(s[5]-'0')*10+s[6]-'0';
		int DD=(s[8]-'0')*10+s[9]-'0';
		for (int i=1;i<MMM;++i)
			now+=days[i];
		now+=DD-1;
		now*=24*60*60;
		int HH,MM,SS;
		scanf("%d:%d:%d:",&HH,&MM,&SS);
		gets(s);
		now+=HH*60*60+MM*60+SS;
		Q.push(now);
		while (Q.front()<=now-n) Q.pop();
		if (Q.size()>=m)
		{
			printf("2012-%02d-%02d %02d:%02d:%02d\n",MMM,DD,HH,MM,SS);
			return 0;
		}
	}
	puts("-1");
	return 0;
}