#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
int n,i,ans,a[N];
bool s[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
		if(a[i]>1&&!s[a[i]-1])
			s[a[i]-1]=1,ans++;
		else
			if(!s[a[i]])
				s[a[i]]=1,ans++;
			else
				if(!s[a[i]+1])
					s[a[i]+1]=1,ans++;
	printf("%d",ans);
}