#include<cstdio>
#include<cstring>
#include<set>
typedef unsigned long long ull; 
using std::set;
int n;
char s[1000];
ull num;
set<ull>hash;
signed main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s+1);
		num=0;
		int len=strlen(s+1);
		for(register int i=1;i<=len;i++)
		{
			if(s[i]!='k'&&s[i]!='u')
				num=num*27+s[i]-'a'+1;
			else if(s[i]=='u')
			{
				num=num*27+'o'-'a'+1;
				num=num*27+'o'-'a'+1;
			}
			else
			{
				int j=i+1;
				while(s[j]=='k')
					j++;
				if(s[j]=='h')
					num=num*27+'h'-'a'+1,i=j;
				else
					num=num*27+'k'-'a'+1;
			}
		}
		hash.insert(num);
	}
	printf("%d\n",hash.size());
	return 0;
}