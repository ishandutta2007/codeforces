#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char s[100001];
int t[100001],u[100001],a[100001],m[100001];
int main(){
	scanf("%s",s+1);int n=strlen(s+1);
	for(int i=1;i*2<=n;i++)swap(s[i],s[n-i+1]);
	for(int i=n;i;i--){
		while(a[0]&&s[i]<s[a[a[0]]])a[0]--;
		a[++a[0]]=i;
	}
	for(int i=n,j=1;i;)
		if(t[0]==0||s[a[j]]<s[t[t[0]]]){
			while(i>a[j])t[++t[0]]=i--;
			u[++u[0]]=i;i--;j++;
		}
		else u[++u[0]]=t[t[0]--];
	while(t[0])u[++u[0]]=t[t[0]--];
	for(int i=1;i<=u[0];i++)printf("%c",s[u[i]]);
}