#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int cnt[30];
char s[105];
char str[105];
//char tr[205];
int len;
int l,r;
int lf,rg;

bool ok()
{
	for(int i=0;i+1<len;++i)
	{
		if(abs(str[i]-str[i+1])==1) return false;
	}
	return true;
}

void solve()
{
	memset(cnt,0,sizeof(cnt));
	scanf("%s",s);
	len=strlen(s);
	for(int i=0;i<len;++i)
	{
		cnt[s[i]-'a']++;
	}
	for(l=0,r=25,lf=0,rg=len-1;l<26&&r>=0;l+=2,r-=2)
	{
		while(cnt[l]>0)
		{
			--cnt[l];
			str[lf++]='a'+l;
		}
		while(cnt[r]>0)
		{
			--cnt[r];
			str[rg--]='a'+r;
		}
	}
	str[len]='\0';
//	puts(str);
	if(ok())
	{
		printf("%s\n",str);
		return;
	}
	for(int i=0;i<len;i++)
	{
		cnt[s[i]-'a']++;
	}
	for(l=1,r=24,lf=0,rg=len-1;l<26&&r>=0;l+=2,r-=2)
	{
		while(cnt[l]>0)
		{
			--cnt[l];
			str[lf++]='a'+l;
		}
		while(cnt[r]>0)
		{
			--cnt[r];
			str[rg--]='a'+r;
		}
	}
//	puts(str);
	if(ok())
	{
		printf("%s\n",str);
		return;
	}
	puts("No answer");
}

int main(){
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;++i) solve();
	return 0;
}