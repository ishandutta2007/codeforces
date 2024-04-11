#include<cstdio>
#include<algorithm>
using namespace std;

char s[100002];
long long a[26][26],b[26];
int main(){
	scanf("%s",s+1);
	for(int i=1;s[i];i++){
		for(int j=0;j<26;j++)
			a[s[i]-'a'][j]+=b[j];
		b[s[i]-'a']++;
	}
	long long ans=0;
	for(int i=0;i<26;i++)
		ans=max(ans,b[i]);
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			ans=max(ans,a[i][j]);
	printf("%lld\n",ans);
}