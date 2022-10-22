#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[200][200];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",s[i]);
	int r=-1,c=-1;
	int b,e;
	for(int i=0;i<n;i++) {
		b=-1;
		e=-1;
		for(int j=0;j<m;j++) {
			if(s[i][j]=='B' && r==-1) {
				if(b==-1) b=j;
				e=j;
			}
		}
		if(b!=-1) r=(b+e)>>1;
	}
	for(int i=0;i<m;i++) {
		b=-1;
		e=-1;
		for(int j=0;j<n;j++) {
			if(s[j][i]=='B' && c==-1) {
				if(b==-1) b=j;
				e=j;
			}
		}
		if(b!=-1) c=(b+e)>>1;
	}
	printf("%d %d",c+1,r+1);
	return 0;
}