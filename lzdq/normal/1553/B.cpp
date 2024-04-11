#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,m;
char s[MAXN],t[MAXN],c[MAXN];
int w[MAXN];
int kmp[MAXN];
bool Check(){
	int l=strlen(c+1);
	for(int i=2,j=0; i<=l; i++){
		while(j&&c[j+1]!=c[i]) j=kmp[j];
		if(c[j+1]==c[i]) j++;
		kmp[i]=j;
	}
	for(int i=1,j=0; i<=n; i++){
		while(j&&s[i]!=c[j+1]) j=kmp[j];
		if(s[i]==c[j+1]) j++;
		if(j==l) return 1;
	}
	return 0;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		for(int i=2,r=1; i<=m; i++){
			if(i<=r+w[r]) w[i]=min(w[r*2-i],r+w[r]-i);
			else w[i]=0;
			while(i+w[i]+1<=m&&t[i-w[i]-1]==t[i+w[i]+1]) w[i]++;
			if(i+w[i]>r+w[r]) r=i;
		}
		int p=0;
		for(int i=1; i<m; i++)
			if(w[m-i]==i) p=i;
		memcpy(c+1,t+1,m-p);
		c[m-p+1]=0;
		bool ans=Check();
		p=0;
		for(int i=1; i<m; i++)
			if(w[i+1]==i) p=i;
		memcpy(c+1,t+p+1,m-p);
		reverse(c+1,c+m-p+1);
		c[m-p+1]=0;
		ans|=Check();
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}