#include<bits/stdc++.h>
#define N 100009
using namespace std;

int n; char a[N],b[N],s[N];
bool check(){
	int i,num=1;
	for (i=1; i<=n+1 && num<=n; i++) if (s[i]==a[num]) num++;
	if (num<=n) return 0;
	num=1;
	for (i=1; i<=n+1 && num<=n; i++) if (s[i]==b[num]) num++;
	if (num<=n) return 0; return 1;
}
int main(){
	scanf("%d%s%s",&n,a+1,b+1);
	int i,j,ans=0;
	for (i=1; i<=n; i++) if (a[i]!=b[i]){
		for (j=1; j<=i; j++) s[j]=a[j];
		for (j=i; j<=n; j++) s[j+1]=b[j];
		if (check()) ans++;
		for (j=1; j<=i; j++) s[j]=b[j];
		for (j=i; j<=n; j++) s[j+1]=a[j];
		if (check()) ans++;
		printf("%d\n",ans); break;
	}
	return 0;
}