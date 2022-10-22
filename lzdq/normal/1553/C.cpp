#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
char s[20];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%s",s+1);
		int ans=10,s1=0,s2=0;
		for(int i=1; i<=10; i++){
			if(s[i]=='?'){
				if(i&1) s1++;
			}
			if(s[i]=='1'){
				if(i&1) s1++;
				else s2++;
			}
			if(11-i>>1<s1-s2){
				ans=i;
				break;
			}
		}
		s1=s2=0;
		for(int i=1; i<=10; i++){
			if(s[i]=='?'){
				if(!(i&1)) s2++;
			}
			if(s[i]=='1'){
				if(i&1) s1++;
				else s2++;
			}
			if(10-i>>1<s2-s1){
				ans=min(ans,i);
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}