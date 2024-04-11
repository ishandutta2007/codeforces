#include<iostream>
#include<cstdlib>
using namespace std;
int A[10];
int pos[10];
void Q(int T)
{
	cout<<"next";
	for(int i=0;i<10;i++)if(T>>i&1)cout<<" "<<i;
	cout<<endl;
	string s;
	getline(cin,s);
	if(s=="stop")
	{
		exit(0);
	}
	int si=0;
	int K=0;
	while(s[si]!=' ')K=K*10+s[si++]-'0';
	si++;
	for(int i=0;i<K;i++)
	{
		while(si<s.size()&&s[si]!=' ')
		{
			pos[s[si++]-'0']=i;
		}
		si++;
	}
}
main()
{
	for(int i=0;;i++)
	{
		Q(3);
		Q(1);
		if(pos[0]==pos[1])break;
	}
	while(pos[0]!=pos[2])Q(1023);
	puts("done");
}