#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 20
template<class T>
void Read(T &x){
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
int n,a[MAXN+10][MAXN+10],m;
bool check(){
	int i,j,cnt;
	for(i=1;i<=n;i++){
		cnt=0;
		for(j=1;j<=m;j++)
			if(a[i][j]!=j)
				cnt++;
		if(cnt>2)
			return 0;
	}
	return 1;
}
int main()
{
	Read(n),Read(m);
	int i,j,k;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			Read(a[i][j]);
	if(check()){
		puts("YES");
		return 0;
	}
	for(i=1;i<=m;i++){
		for(j=i+1;j<=m;j++){
			for(k=1;k<=n;k++)
				swap(a[k][i],a[k][j]);
			if(check()){
				puts("YES");
				return 0;
			}
			for(k=1;k<=n;k++)
				swap(a[k][i],a[k][j]);	
		}
	}
	puts("NO");
}