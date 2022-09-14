#include<iostream>
using namespace std;
int T;
string S;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>S;
		int ai=0;
		while(ai<S.size()&&S[ai]!='a')ai++;
		if(ai==S.size())
		{
			cout<<"NO\n";
			continue;
		}
		int l=ai-1,r=ai+1;
		bool out=false;
		for(char c='b';c<='z';c++)
		{
			if(l<0&&r==S.size())break;
			if(l>=0&&S[l]==c)l--;
			else if(r<S.size()&&S[r]==c)r++;
			else out=true;
		}
		cout<<(out||l>0||r<S.size()?"NO\n":"YES\n");
	}
}