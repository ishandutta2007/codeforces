#include<bits/stdc++.h>
#define N 200005

int n,a[N];
char s[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%s",s+1);
	std::sort(a+1,a+n+1);
	int j=n+1;
	for(int i=1;i<=n;i++)
		j-=s[i]!=s[i-1];
	for(int o=1,i=j,c=s[1];o<=n;o++)
		if(s[o]!=s[o-1])
			printf("%d %c\n",a[j++],s[o]);
		else
			printf("%d %c\n",a[--i],c='L'^'R'^c);
}