#include<iostream>
#include<cstdio>
#include<set>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int t[4];
int main()
{
	int t1,t2;scanf("%d%d%d%d%d",&t[1],&t[2],&t[3],&t1,&t2);
	t1*=5;t2*=5;t[1]*=5;
	t[1]*=2;t1*=2;t2*=2;t[2]*=2;t[3]*=2;
	if(t[2]>0||t[3]>0)t[1]++;
	if(t[3]>0)t[2]++;
	sort(t+1,t+4);
	if((t[1]<=t1&&t1<=t[2]&&t[1]<=t2&&t2<=t[2])||(t[2]<=t1&&t1<=t[3]&&t[2]<=t2&&t2<=t[3])||((t[3]<=t1||t1<=t[1])&&(t[3]<=t2||t2<=t[1])))
	puts("YES");
	else puts("NO");
	return 0;
}