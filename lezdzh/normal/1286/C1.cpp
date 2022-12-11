#include<cstdio>
#include<iostream>
using namespace std;

int a[5501][26];
int b[5501][26];
int at,bt,c[5501];
long long h[5501];
int ans[101];
int main(){
	int n;
	scanf("%d",&n);
	printf("? %d %d\n",1,n);
	fflush(stdout);
	if(n==1){
		string s;
		cin>>s;
		cout<<"! "<<s<<"\n";
		fflush(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			at++;
			string s;
			cin>>s;
			for(int i=0;i<s.length();i++)
				a[at][s[i]-'a']++;
		}
	printf("? %d %d\n",2,n);
	fflush(stdout);
	for(int i=2;i<=n;i++)
		for(int j=i;j<=n;j++){
			bt++;
			string s;
			cin>>s;
			for(int i=0;i<s.length();i++)
				b[bt][s[i]-'a']++;
		}
	for(int i=1;i<=at;i++){
		for(int j=0;j<26;j++)
			h[i]=(1ll*h[i]*10007+a[i][j])%1000000009;
	}
	for(int i=1;i<=bt;i++){
		int hh=0;
		for(int j=0;j<26;j++)
			hh=(10007ll*hh+b[i][j])%1000000009;
		for(int j=1;j<=at;j++)
			if(!c[j]&&hh==h[j]){
				c[j]=1;
				break;
			}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=at;j++)
			if(!c[j]){
				int z=0;
				for(int k=0;k<26;k++)
					z+=a[j][k];
				if(z!=i)continue;
				for(int k=1;k<i;k++)
					a[j][ans[k]]--;
				for(int k=0;k<26;k++)
					if(a[j][k])ans[i]=k;
				c[j]=1;
			}
	}
	printf("! ");
	for(int i=1;i<=n;i++)
		printf("%c",ans[i]+'a');
	printf("\n");
	fflush(stdout);
}