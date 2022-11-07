#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n; char a[1005][6];
int read(){
	int x=0; char cr=getchar(); bool flag=0;
	while (cr<'0' || cr>'9'){ if (cr=='-') flag=1; cr=getchar(); }
	while (cr>='0' && cr<='9'){ x=x*10+cr-'0'; cr=getchar(); }
	return (flag)?-x:x;
}
int main(){
	scanf("%d",&n);
	int i;
	for (i=1; i<=n; i++){
		scanf("%s",a[i]+1);
	}int j;
	for (i=1; i<=n; i++){
		if (a[i][1]=='O' && a[i][2]=='O'){
			a[i][1]=a[i][2]='+';break;
		} else if (a[i][4]=='O' && a[i][5]=='O'){
			a[i][4]=a[i][5]='+';break;}
		}
	if (i>n) puts("NO"); else{
		puts("YES");
		for (i=1; i<=n; i++,puts(""))
			for (j=1; j<=5; j++) putchar(a[i][j]);
			}
	return 0;
}