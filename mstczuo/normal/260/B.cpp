# include <iostream>
# include <cstdio>
using namespace std;

const int C[11][2]={{1,0},{2,0},{2,3},{4,0},{5,0},{2,6},{7,0},{8,0},{9,6},{10,3},{2,3}};
const int Day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int HASH[3][12][31],D[1200],Cnt,Ans,w;
char a[120000], ans[1200][11];

void pushdata(const char *p)
{
	static int dd,mm,yy;
	static int *temp;
	if(*(p+6)!='2' || *(p+7)!='0' || *(p+8)!='1')return;
	
	dd=10*(*(p+0)-'0')+(*(p+1)-'0');
	mm=10*(*(p+3)-'0')+(*(p+4)-'0');
	yy=2010+(*(p+9)-'0');
	if(yy<2013 || yy>2015)return;
	if(mm<1 || mm>12)return;
	if(dd<1 || dd>Day[mm-1])return;
	
	temp=&HASH[yy-2013][mm-1][dd-1];
	if(*temp==0)*temp=++Cnt,sprintf(ans[Cnt],"%02d-%02d-%d",dd,mm,yy);
	D[*temp]++;
}
int main()
{
	scanf("%s",a);
	for(int i=0;a[i];i++)
	{
		w=C[w][(a[i]=='-')];
		if(w==10)pushdata(a+(i-9));
	}

	Ans=1;
	for(int i=2;i<=Cnt;i++)
		if(D[i]>D[Ans])Ans=i;
	printf("%s\n",ans[Ans]);
}