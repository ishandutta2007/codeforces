#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,m;
char s[MAXN];
int ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		int x=0,y=0;
		ans=0;
		scanf("%s",s);
		for(int i=0; s[i]; i++){
			if(s[i]=='(') x++;
			else if(s[i]==')'){
				if(x) x--,ans++;
			}else if(s[i]=='[') y++;
			else if(y) y--,ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}