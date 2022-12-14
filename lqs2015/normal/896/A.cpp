#include<bits/stdc++.h>
using namespace std;
long long len[111];
string s,s2,s3,s4;
int q,n;
long long k;
char get(int n,long long k)
{
	if (!n) return s[k-1];
	if (k<=(long long)s2.size()) return s2[k-1];
	k-=(long long)s2.size();
	if (n>53) return get(n-1,k);
	if (k<=len[n-1]) return get(n-1,k);
	k-=len[n-1];
	if (k<=(long long)s3.size()) return s3[k-1];
	k-=(long long)s3.size();
	if (k<=len[n-1]) return get(n-1,k);
	k-=len[n-1];
	return s4[k-1];
}
int main()
{
	s="What are you doing at the end of the world? Are you busy? Will you save us?";
	s2="What are you doing while sending \"";
	s3="\"? Are you busy? Will you send \"";
	s4="\"?";
	len[0]=75;
	for (int i=1;i<=100;i++) len[i]=2ll*len[i-1]+(int)s2.size()+(int)s3.size()+(int)s4.size();
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%lld",&n,&k);
		if (n<=53) 
		{
			if (len[n]<k) 
			{
				printf(".");
				continue;
			}
		}
		printf("%c",get(n,k));
	}
	printf("\n");
	return 0;
}