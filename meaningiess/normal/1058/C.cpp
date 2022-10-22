#include<iostream>
#include<cstdio>
using namespace std;
int n,a[101];
char g[101];
int chk(int x)
{
	int sum=0,i,res=0;
	for (i=1;i<=n;i++){sum+=a[i];if (sum>x) return 0;if (sum==x) sum=0,res++;}
	if ((sum!=x && sum!=0)||res<=1) return 0;return 1;
}
int main()
{
    cin>>n;scanf("%s",g+1);
    for (int i=1;i<=n;i++) a[i]=g[i]-'0';
    for (int i=0,s=0;i<n;i++) {s+=a[i];if (chk(s)){puts("YES");return 0;}}
    puts("NO");
}