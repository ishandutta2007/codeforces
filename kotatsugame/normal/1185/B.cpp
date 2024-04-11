#include<cstdio>
#include<cstring>
using namespace std;
int N;
char s[1<<20],t[1<<20];
main()
{
	scanf("%d\n",&N);
	for(;N--;)
	{
		scanf("%s\n%s\n",s,t);
		int i=0,j=0;
		int S=strlen(s),T=strlen(t);
		bool flag=1;
		while(i<S&&j<T)
		{
			int ca=1,cb=1;
			while(i+1<S&&s[i]==s[i+1])i++,ca++;
			while(j+1<T&&t[j]==t[j+1])j++,cb++;
			if(s[i]!=t[j]||ca>cb)
			{
				flag=0;
				break;
			}
			i++,j++;
		}
		if(i==S&&j<T||i<S&&j==T)flag=0;
		puts(flag?"YES":"NO");
	}
}