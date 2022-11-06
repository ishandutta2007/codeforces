#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;
char a[100],b[100];
int count[100];
int la,lb;
int ans[100];
template<class Tp>
inline bool greater(Tp a,Tp b)
{
	return a>b;
}
bool search(int step)
{
	if(step==lb+1)
		return true;
	if(count[b[step]-'0'])
	{
		count[b[step]-'0']--;
		if(search(step+1))
		{
			count[b[step]-'0']++;
			ans[step]=b[step]-'0';
			return true;
		}
		count[b[step]-'0']++;
	}
	for(int i=b[step]-'0'-1;i>=0;--i)
		if(count[i])
		{
			ans[step]=i;
			count[i]--;
			for(int j=9;j>=0;--j)
				for(int k=1;k<=count[j];++k)
					ans[++step]=j;
			count[i]++;
			return true;
		}
	return false;
}
signed main()
{
	register int i,j;
	scanf("%s",a+1);
	scanf("%s",b+1);
	if((la=strlen(a+1))<(lb=strlen(b+1)))
	{
		sort(a+1,a+la+1,greater<char>);
		printf("%s\n",a+1);
		return 0;
	}
	for(i=1;i<=la;++i)
		count[a[i]-'0']++;
	search(1);
	for(i=1;i<=lb;++i)
		printf("%d",ans[i]);
	return 0;
}