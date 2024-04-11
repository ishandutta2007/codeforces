#include<bits/stdc++.h>
using namespace std;
int m,n,x;
bool p[61];
int t;
int main()
{
	scanf("%d %d",&m,&n);
	for(int i=0;i<n;i++) {
		cout<<m<<endl;
		fflush(stdout);
		scanf("%d",&t);
		if(t==0) exit(0);
		if(t==-1) p[i]=true;
		else p[i]=false;
	}
	int l=1,r=m-1;
	for(int i=0;i<600;i++) {
		m=(l+r)>>1;
		cout<<m<<endl;
		fflush(stdout);
		scanf("%d",&t);
		if(t==0) exit(0);
		if((t==-1 && p[i%n]) || (t==1 && !p[i%n])) r=m-1;
		else l=m+1;
	}
	return 0;
}