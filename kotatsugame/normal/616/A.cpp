#include<cstdio>
#include<string>
using namespace std;
string rd()
{
	char c;
	string ret;
	while((c=getchar())=='0');
	if(c=='\n')ret="0";
	else
	{
		ret+=c;
		while((c=getchar())!='\n')ret+=c;
	}
	return ret;
}
main()
{
	string A=rd();
	string B=rd();
	if(A.size()<B.size())putchar('<');
	else if(A.size()>B.size())putchar('>');
	else putchar(A<B?'<':A>B?'>':'=');
	putchar(10);
}