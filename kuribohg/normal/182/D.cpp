#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int MAXL=200010;
int len1,len2,next[MAXL],ans;
string a,b;
long long T1,T2,T;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
void initKMP(string p)
{
	int j=0,len=p.length();
	for(int i=1;i<len;i++)
	{
		while(j&&p[i]!=p[j]) j=next[j];
		if(p[i]==p[j]) j++;
		next[i+1]=j;
	}
}
int main()
{
	cin>>a>>b;
	len1=a.length(),len2=b.length();
	initKMP(a);
	if(len1%(len1-next[len1])==0) T1=len1-next[len1];
	else T1=len1;
	initKMP(b);
	if(len2%(len2-next[len2])==0) T2=len2-next[len2];
	else T2=len2;
	T=T1*T2/gcd(T1,T2);
	for(int i=1;T*i<=max(len1,len2);i++)
		if(len1%(T*i)==0&&len2%(T*i)==0) ans++;
	if(T>max(len1,len2)) ans=0;
	else if(a.substr(0,T)!=b.substr(0,T)) ans=0;
	printf("%d\n",ans);
	return 0;
}