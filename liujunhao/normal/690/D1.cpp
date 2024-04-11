#include<cstdio>
#include<algorithm>
using namespace std;
void Read(int &x){
	static char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
int n,m,ans;
char s[200];
void read(){
	Read(n),Read(m);
	while(n--)
		scanf("%s",s);
}
void solve(){
	int i;
	for(i=0;i<m;i++)
		if(s[i]=='B')
			if(!i||s[i-1]!='B')
				ans++;
}
int main()
{
	read();
	solve();
	printf("%d\n",ans);
}