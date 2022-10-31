#include<cstdio>
#include<algorithm>
using namespace std;
void Read(int &x){
	static char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
char s[20];
int dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}},ans;
int main()
{
	scanf("%s",s);
	for(int d=0;d<8;d++){
		if(s[0]+dir[d][0]>='a'&&s[0]+dir[d][0]<='h'&&s[1]+dir[d][1]>='1'&&s[1]+dir[d][1]<='8')
			ans++;
	}
	printf("%d\n",ans);
}