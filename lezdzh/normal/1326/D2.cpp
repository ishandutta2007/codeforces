#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

char s[1000002];
int a[2000003],f[2000003];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		scanf("%s",s+1);
		int n=strlen(s+1);
		for(int i=1;i<=n;i++){
			a[i*2]=s[i];
			a[i*2+1]=' ';
		}
		a[1]=' ';
		f[1]=0;  
		int mx=1;
		for(int i=2;i<=2*n+1;i++){  
			f[i]=max(1,min(f[mx]+mx-i,f[2*mx-i]));  
			while(i-f[i]>0&&i+f[i]<=2*n+1&&a[i-f[i]]==a[i+f[i]])f[i]++;  
			//printf("%d %d\n",i,f[i]);
			if(f[i]+i>f[mx]+mx)
				mx=i; 
		}
		int w=0;
		while(w+1<n-w&&s[w+1]==s[n-w+1-1])w++;
		int ans=-1,anst,ansp;
		for(int i=2*w+1;i<2*(n-w+1);i++){
			int o=min(min(i-w*2,2*(n-w+1)-i),f[i])-1;
			if(o+1!=i-w*2&&o+1!=2*(n-w+1)-i)continue;
			if(w*2+o>ans)ans=w*2+o,ansp=i,anst=o+1;
		}
		for(int i=1;i<=w;i++)
			printf("%c",s[i]);
		for(int i=ansp-anst+1;i<=ansp+anst-1;i++)
			if(a[i]!=' ')printf("%c",a[i]);
		for(int i=n-w+1;i<=n;i++)
			printf("%c",s[i]);
		printf("\n");
	}
}