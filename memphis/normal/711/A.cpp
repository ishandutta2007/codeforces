#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
const int N=1005;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int n;
bool tag;
char s[N][10];

int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%s",s[i]);
		if(!tag){
			if(s[i][0]==s[i][1] && s[i][0]=='O')
				s[i][0]=s[i][1]='+',tag=1;
			else if(s[i][3]==s[i][4] && s[i][3]=='O')
				s[i][3]=s[i][4]='+',tag=1;
		}
	}
	if(tag){
		puts("YES");
		rep(i,1,n) puts(s[i]);
	}
	else puts("NO");
}