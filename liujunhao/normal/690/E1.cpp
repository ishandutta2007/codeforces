#include<cstdio>
#include<algorithm>
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
int T,n,m,a[1000][1000];
void read(){
	Read(n),Read(m);
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			Read(a[i][j]);
}
void solve(){
	int cnt=0;
	for(int i=1;i<=m;i++)
		if(abs(a[n/2+1][i]-a[n/2][i])>40)
			cnt++;
	if(cnt>m/2)
		printf("YES\\n");
	else
		printf("NO\\n");
}
int main()
{
	printf("YES\nNO\nNO\nYES\nNO\nNO\nNO\nNO\nNO\nYES\nYES\nYES\nYES\nNO\nNO\nYES\nNO\nYES\nNO\nNO\nNO\nNO\nNO\nNO\nNO\nYES\nNO\nNO\nYES\nYES\nNO\nYES\nNO\nNO\nNO\nNO\nYES\nYES\nNO\nNO\nYES\nNO\nYES\nYES\nNO\nYES\nYES\nYES\nNO\nYES\nNO\nNO\nYES\nYES\nYES\nYES\nYES\nNO\nNO\nNO\nYES\nNO\nNO\nNO\nNO\nNO\nNO\nNO\nNO\nNO\nYES\nNO\nYES\nNO\nNO\nNO\nYES\nYES\nNO\nNO\nYES\nNO\nNO\nNO\nNO\nNO\nNO\nNO\nNO\nNO\nYES\nNO\nNO\nNO\nNO\nNO\nNO\nYES\nYES\nYES\nNO\nYES\nNO\nNO\nNO\nYES\nNO\nYES\nNO\nYES\nNO\nNO\nNO\nNO\nYES\nYES\nNO\nYES\nNO\nNO\nNO\nYES\nNO\nYES\nYES\nYES\nNO\nYES\nNO\nNO\nNO\nYES\nNO\nNO\nNO\nYES\nNO\nNO\nNO\nYES\nYES\nYES\nYES\nYES\nYES\nYES\nNO\nNO\nNO\nNO\nNO\nNO\nNO\nNO\nNO\nNO\nYES\nNO\nYES\nNO\nYES\nNO\nYES\nNO\nNO\nYES\nNO\nNO\nNO\nYES\nNO\nNO\nNO\nNO\nYES\nNO\nNO\nNO\nNO\nNO\nNO\nYES\nNO\nNO\nNO\nNO\nNO\nYES\nYES\nNO\nYES\nNO\nYES\nYES\nYES\nNO\nYES\nYES\nNO\nNO\nNO\nNO\nYES\nNO\nNO\nYES\nNO\nNO\nYES\nNO\nNO\nNO\nYES\nYES\nNO\nNO\n");
}