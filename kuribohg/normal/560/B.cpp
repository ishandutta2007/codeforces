#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a,b,c,d;
int main()
{
	scanf("%d%d%d%d%d%d",&n,&m,&a,&b,&c,&d);
	if(a+c<=n&&max(b,d)<=m) {puts("YES");return 0;}
	swap(a,b);
	if(a+c<=n&&max(b,d)<=m) {puts("YES");return 0;}
	swap(c,d);
	if(a+c<=n&&max(b,d)<=m) {puts("YES");return 0;}
	swap(a,b);
	if(a+c<=n&&max(b,d)<=m) {puts("YES");return 0;}
	swap(n,m);
	if(a+c<=n&&max(b,d)<=m) {puts("YES");return 0;}
	swap(a,b);
	if(a+c<=n&&max(b,d)<=m) {puts("YES");return 0;}
	swap(c,d);
	if(a+c<=n&&max(b,d)<=m) {puts("YES");return 0;}
	swap(a,b);
	if(a+c<=n&&max(b,d)<=m) {puts("YES");return 0;}
	puts("NO");
	return 0;
}