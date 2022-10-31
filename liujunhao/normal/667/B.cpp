#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const double pi=acos(-1);
#define MAXN 100000
int n,a[MAXN+10],mx;
long long sum;
void Read(int &x){
	static char c;
	bool f=0;
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
int main()
{
	Read(n);
	for(int i=1;i<=n;i++)
		Read(a[i]),sum+=a[i],mx=max(mx,a[i]);
	if(sum-mx>mx)
		printf("0\n");
	else
		printf("%I64d\n",2*mx-sum+1);
}