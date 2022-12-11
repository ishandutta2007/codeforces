#include<cstdio>
char s[5011];
bool hw[5001][5001];
int a[5001][5001],b[5001];
int main(){
	scanf("%s",s+1);
	int n=0;
	for(;s[n+1];n++);
	for(int i=1;i<=n;i++)
		for(int l=1;l+i-1<=n;l++){
			int r=l+i-1;
			hw[l][r]=s[l]==s[r]&&(r-l<=1||hw[l+1][r-1]);
			a[l][r]=hw[l][r]?a[l][l+i/2-1]+1:0;
			b[a[l][r]]++;
		}
	for(int i=n;i;i--)
		b[i-1]+=b[i];
	for(int i=1;i<=n;i++)
		printf("%d ",b[i]);
}