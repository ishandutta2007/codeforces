#include<bits/stdc++.h>
using namespace std;
int c[20];
int d[20];
int p[20];
char s[200000];
int x[200000];
int y[200000];
int rt;
int n;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++) c[s[i]-'0']++;
	for(int i=0;i<10;i++) p[i]=d[i]=c[i];
	//for(int i=0;i<10;i++) cerr<<p[i]<<endl;
	int a=0,b=0;
	int ans=-1000000000;
	int ca;
	int t;
	int o;
	for(int i=1;i<10;i++)
	{
		for(int j=1;j<10;j++) {
			c[i]--;
			d[j]--;
			ca=0;
			//ca=p[0];
			//c[0]=d[0]=0;
			if(c[i]>=0 && d[j]>=0 && i+j==10) {
				if(i+j==10) ca++;
				
				//cerr<<ca<<endl;
				for(int k=0;k<=9;k++) {
					t=min(c[k],d[9-k]);
					c[k]-=t;
					d[9-k]-=t;
					ca+=t;
				}
				ca+=min(c[0],d[0]);
				if(ca>ans) {
					a=i;
					b=j;
					rt=min(c[0],d[0]);
					ans=ca;
				}
			}
			c[i]++;
			d[j]++;
			for(int k=0;k<10;k++) c[k]=d[k]=p[k];
		}
	}
	//cout<<a<<" "<<b<<" "<<ans;
	if(ans<0) {
		for(int i=9;i>=0;i--) {
			for(int j=0;j<c[i];j++) printf("%d",i);
		}
		printf("\n");
		for(int i=9;i>=0;i--) {
			for(int j=0;j<c[i];j++) printf("%d",i);
		}
		printf("\n");
		return 0;
	}
	int k=0;
	for(int i=0;i<rt;i++) {
		x[k]=y[k]=0;
		k++;
	}
	c[0]-=rt;
	d[0]-=rt;
	x[k]=a;
	y[k]=b;
	k++;
	c[a]--;
	d[b]--;	
	for(int i=0;i<=9;i++) {
		t=min(c[i],d[9-i]);
		c[i]-=t;
		d[9-i]-=t;
		for(int j=0;j<t;j++) {
			x[k]=i;
			y[k]=9-i;
			k++;
		}
	}
	for(int r=0;r<10;r++) {
		for(int q=0;q<10;q++) {
			while(c[r]>0 && d[q]>0) {
				c[r]--;
				d[q]--;
				x[k]=r;
				y[k]=q;
				k++;
			}
		}
	}
	for(int i=n-1;i>=0;i--) printf("%d",x[i]);
	printf("\n");
	for(int i=n-1;i>=0;i--) printf("%d",y[i]);
	printf("\n");
	return 0;
}