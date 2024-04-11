#include<bits/stdc++.h>
using namespace std;


void out(int t)
{
	if (t==0)	printf("zero\n");
	if (t==1)	printf("one\n");
	if (t==2)	printf("two\n");
	if (t==3)	printf("three\n");
	if (t==4)	printf("four\n");
	if (t==5)	printf("five\n");
	if (t==6)	printf("six\n");
	if (t==7)	printf("seven\n");
	if (t==8)	printf("eight\n");
	if (t==9)	printf("nine\n");
	if (t==10)	printf("ten\n");
	if (t==11)	printf("eleven\n");
	if (t==12)	printf("twelve\n");
	if (t==13)	printf("thirteen\n");
	if (t==14)	printf("fourteen\n");
	if (t==15)	printf("fifteen\n");
	if (t==16)	printf("sixteen\n");
	if (t==17)	printf("seventeen\n");
	if (t==18)	printf("eighteen\n");
	if (t==19)	printf("nineteen\n");
}
int n;
int main()
{
	scanf("%d",&n);
	if (n<20)	{out(n);return 0;}
	if (n<30)
	{
		printf("twenty");
		if (n%10!=0)	{printf("-");out(n%10);}else	printf("\n");
		return 0;
	}
	if (n<40)
	{
		printf("thirty");
		if (n%10!=0)	{printf("-");out(n%10);}else	printf("\n");
		return 0;
	}
	if (n<50)
	{
		printf("forty");
		if (n%10!=0)	{printf("-");out(n%10);}else	printf("\n");
		return 0;
	}
	if (n<60)
	{
		printf("fifty");
		if (n%10!=0)	{printf("-");out(n%10);}else	printf("\n");
		return 0;
	}
	if (n<70)
	{
		printf("sixty");
		if (n%10!=0)	{printf("-");out(n%10);}else	printf("\n");
		return 0;
	}
	if (n<80)
	{
		printf("seventy");
		if (n%10!=0)	{printf("-");out(n%10);}else	printf("\n");
		return 0;
	}
	if (n<90)
	{
		printf("eighty");
		if (n%10!=0)	{printf("-");out(n%10);}else	printf("\n");
		return 0;
	}
	if (n<100)
	{
		printf("ninety");
		if (n%10!=0)	{printf("-");out(n%10);}else	printf("\n");
		return 0;
	}
	return 0;
}