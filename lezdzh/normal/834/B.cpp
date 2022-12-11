#include<cstdio>
using namespace std;
char s[1000010];
int a[1000010];
bool vis[26];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		if(!vis[s[i]-'A']){
			vis[s[i]-'A']=1;
			a[i]++;
		}
	for(int i=0;i<26;i++)
		vis[i]=0;
	for(int i=n;i;i--)
		if(!vis[s[i]-'A']){
			vis[s[i]-'A']=1;
			a[i+1]--;
		}
	bool b=0;
	for(int i=1,o=0;i<=n;i++){
		o+=a[i];
		if(o>k)b=1;
	}
	printf(b?"YES\n":"NO\n");
}