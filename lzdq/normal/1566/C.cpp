#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n,ans;
char s1[MAXN],s2[MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		scanf("%s%s",s1+1,s2+1);
		ans=0;
		int c=-1;
		for(int i=1; i<=n; i++){
			if(s1[i]!=s2[i]){
				if(c==0) ans++;
				ans+=2;
				c=-1;
			}else if(s1[i]=='0'){
				if(c==-1) c=0;
				else if(c==0) ans++;
				else ans+=2,c=-1;
			}else{
				if(c==-1) c=1;
				else if(c==0) ans+=2,c=-1;
			}
		}
		if(c==0) ans++;
		printf("%d\n",ans);
	}
	return 0;
}