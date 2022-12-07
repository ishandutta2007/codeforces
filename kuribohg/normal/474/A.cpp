#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<iterator>
#include<functional>
#include<bitset>
#include<utility>
#define pb push_back
#define mp make_pair
using namespace std;
string str="qwertyuiopasdfghjkl;zxcvbnm,./";
char op[10],a[100010];
int k;
void work(char a)
{
	int sub=0;
	for(int i=0;i<30;i++) if(a==str[i]) sub=i;
	putchar(str[sub+k]);
}
int main()
{
	scanf("%s",op);
	scanf("%s",a);
	if(op[0]=='R') k=-1;
	else k=1;
	for(int i=0;i<strlen(a);i++) work(a[i]);
	puts("");
	return 0;
}