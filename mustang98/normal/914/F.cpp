#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2") // WINDOWS ONLY
#include <bits/stdc++.h>
using namespace std;
char ch[110000],c[10],s[110000];
bitset<100010>x[30],ans,one;
int n,m;
int main(){
	scanf("%s",ch+1); n=strlen(ch+1);
	for (int i=1;i<=n;i++) x[ch[i]-'a'][i]=1;
	scanf("%d",&m);
	for (int i=0;i<n;i++) one[i]=1;
	for (;m;m--){
		int k1; scanf("%d",&k1);
		if (k1==1){
			int k2; scanf("%d",&k2);
			scanf("%s",c+1); int k3=c[1]-'a';
			x[ch[k2]-'a'][k2]=0;
			x[k3][k2]=1; ch[k2]=c[1];
		} else {
			int l,r;
			scanf("%d%d",&l,&r);
			scanf("%s",s+1);
			int len=strlen(s+1);
			if (r-l+1<len){
				printf("%d\n",0); continue;
			}
			ans=one;
			for (int i=1;i<=len;i++)
				ans&=(x[s[i]-'a']>>i);
			//for (int i=0;i<n;i++) cout<<ans[i]; cout<<endl;
			int w=(ans>>(l-1)).count()-(ans>>(r-len+1)).count();
			printf("%d\n",w);
		}
	}
	return 0;
}