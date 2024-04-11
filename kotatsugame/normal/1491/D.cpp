#include<cstdio>
using namespace std;
int Q;
long long u,v;
main()
{
	scanf("%d",&Q);
	for(;Q--;)
	{
		scanf("%lld%lld",&u,&v);
		int cnt=0;
		bool ok=true,fst=true;
		for(int i=30;i--;)
		{
			if(!(u>>i&1)&&(v>>i&1))
			{
				cnt++;
				fst=false;
			}
			else if((u>>i&1)&&!(v>>i&1))
			{
				if(fst)ok=false;
				if(cnt>0)cnt--;
			}
		}
		puts(ok&&cnt==0?"YES":"NO");
	}
}