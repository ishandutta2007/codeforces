#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout),scanf("%d%d",&n,&m);
	if(n>m) {for(int i=1;i<=m;i++) putchar('B'),putchar('G');for(int i=1;i<=n-m;i++) putchar('B');}
	else {for(int i=1;i<=n;i++) putchar('G'),putchar('B');for(int i=1;i<=m-n;i++) putchar('G');}
	return 0;
}