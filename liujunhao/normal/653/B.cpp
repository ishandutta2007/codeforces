#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[10],c[40][3],d[40][2],tmp[10];
int n,q,ans;
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
bool check(){
	memcpy(tmp,s,sizeof s);
	int i,j;
	for(i=2;i<=n;i++){
		for(j=1;j<=q;j++)
			if(tmp[i-1]==c[j][0]&&tmp[i]==c[j][1]){
				tmp[i]=d[j][0];
				break;
			}
		if(j>q)
			return 0;
	}
	return tmp[n]=='a';
}
void dfs(int i){
	if(i>n){
		if(check()){
			ans++;
		}
		return;
	}
	char a;
	for(a='a';a<='f';a++){
		s[i]=a;
		dfs(i+1);
	}
}
int main()
{
	Read(n),Read(q);
	int i;
	for(i=1;i<=q;i++)
		scanf("%s%s",c[i],d[i]);
	dfs(1);
	printf("%d\n",ans);
}