#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;scanf("%d",&n);
	if(n<1200)puts("1200");
	if(1200<=n&&n<1400)puts("1400");
	if(1400<=n&&n<1600)puts("1600");
	if(1600<=n&&n<1900)puts("1900");
	if(1900<=n&&n<2100)puts("2100");
	if(2100<=n&&n<2300)puts("2300");
	if(2300<=n&&n<2400)puts("2400");
	if(2400<=n&&n<2600)puts("2600");
	if(n>=2600)puts("3000");
}