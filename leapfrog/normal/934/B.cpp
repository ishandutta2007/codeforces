#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k;scanf("%d",&k);
	if(k>2*18) return puts("-1"),0;
	for(int i=1;i<=k/2;i++) putchar('8');
	return k%2?putchar('4'):0,0;
}