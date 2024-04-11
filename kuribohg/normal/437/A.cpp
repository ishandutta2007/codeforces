#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<ctime>
#include<queue>
#include<utility>
#include<cstdlib>
#include<cmath>
using namespace std;
string str[5];
int a[10],minnum=1e9,minsub,maxnum,maxsub,ans1,ans2,ans;
int main()
{
	cin>>str[1]>>str[2]>>str[3]>>str[4];
	for(int i=1;i<=4;i++) a[i]=str[i].length()-2;
	for(int i=1;i<=4;i++)
	{
		if(a[i]<minnum) minnum=a[i],minsub=i;
		if(a[i]>maxnum) maxnum=a[i],maxsub=i;
	}
	sort(a+1,a+5);
	if(a[1]<=a[2]/2) ans1=minsub;
	if(a[4]>=a[3]*2) ans2=maxsub;
	if((ans1&&ans2)||(ans1==0&&ans2==0)) ans=3;
	else ans=(ans1==0?ans2:ans1);
	putchar(ans+'A'-1);
	puts("");
	return 0;
}