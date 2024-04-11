#include<bits/stdc++.h>
using namespace std;
int mi,ma;
int mi1[105],mi2[105],ma1[105],ma2[105];
int n;
char str[1000005];
void pro(int pos)
{
	int i;
	for(i=1;i<=n;i+=2)
	  {
	  	if(i==n)
	  	  {
	  	  	ma1[i/2+1]=mi1[i/2+1]=i;
		  }
		else
		  {
		  	printf("? %d %d\n",i,i+1);
			fflush(stdout);
		  	scanf("%s",str);
		  	while(!(str[0]=='>'||str[0]=='='||str[0]=='<'))
		  	  scanf("%s",str);
		  	if(str[0]=='>')
		  	  ma1[i/2+1]=i,mi1[i/2+1]=i+1;
		  	else
		  	  mi1[i/2+1]=i,ma1[i/2+1]=i+1;
		  }
	  }
	n=(n+1)/2;
	while(n>1)
	  {
	  	for(i=1;i<=n;i+=2)
	  	  {
	  	  	if(i==n)
	  	  	  {
	  	  	  	ma2[i/2+1]=ma1[i];
				mi2[i/2+1]=mi1[i];
			  }
			else
			  {
			  	printf("? %d %d\n",ma1[i],ma1[i+1]);
			  	fflush(stdout);
		  		scanf("%s",str);
		  		while(!(str[0]=='>'||str[0]=='='||str[0]=='<'))
		  	  	  scanf("%s",str);
		  		if(str[0]=='>')
		  	  	  ma2[i/2+1]=ma1[i];
		  		else
		  	  	  ma2[i/2+1]=ma1[i+1];
		  	  	printf("? %d %d\n",mi1[i],mi1[i+1]);
			  	fflush(stdout);
		  		scanf("%s",str);
		  		while(!(str[0]=='>'||str[0]=='='||str[0]=='<'))
		  	  	  scanf("%s",str);
		  		if(str[0]=='<')
		  	  	  mi2[i/2+1]=mi1[i];
		  		else
		  	  	  mi2[i/2+1]=mi1[i+1];
			  }
		  }
		n=(n+1)/2;
		for(i=1;i<=n;i++)
		  ma1[i]=ma2[i],mi1[i]=mi2[i];
	  }
	mi=mi1[1],ma=ma1[1];
	return;
}
int main()
{
	int t,i1;
	scanf("%d",&t);
	for(i1=1;i1<=t;i1++)
	  {
	  	scanf("%d",&n);
	  	mi=0,ma=0;
	  	pro(n);
	  	printf("! %d %d\n",mi,ma);
		fflush(stdout);
	  }
	return 0;
}