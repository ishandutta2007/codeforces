#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n,q;
char s[MAXN];
int Check(int w){
	if(w+2>n||w<=0) return 0;
	return s[w]=='a'&&s[w+1]=='b'&&s[w+2]=='c';
}
int ans;
int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	for(int i=1; i<=n; i++)
		ans+=Check(i);
	while(q--){
		int pos;
		char c[5];
		scanf("%d%s",&pos,c);
		ans-=Check(pos-2)+Check(pos-1)+Check(pos);
		s[pos]=c[0];
		ans+=Check(pos-2)+Check(pos-1)+Check(pos);
		printf("%d\n",ans);
	}
	return 0;
}