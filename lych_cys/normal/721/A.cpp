#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,cnt,h[105]; char s[105];
int read(){
	int x=0; char cr=getchar(); bool flag=0;
	while (cr<'0' || cr>'9') cr=getchar();
	while (cr>='0' && cr<='9'){ x=x*10+cr-'0'; cr=getchar(); }
	return x;
}
int main(){
	scanf("%d%s",&n,s+1);
	int i; bool flag=0;
	for (i=1; i<=n; i++)
		if (s[i]=='W') flag=0;
			else if (flag) h[cnt]++; else{
				h[++cnt]=1; flag=1;
			}
	printf("%d\n",cnt);
	if (cnt)
		for (i=1; i<=cnt; i++) printf("%d%c",h[i],(i<cnt)?' ':'\n');
	return 0;
}