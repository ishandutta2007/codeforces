#include<iostream>
#include<cstring>
using namespace std;
int hsh[30];
int main()
{
	int n,i;char ch;cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>ch;hsh[ch-'a']++;
	}
	for (i=0;i<26;i++) while (hsh[i]--)printf("%c",'a'+i);
}