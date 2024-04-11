#include<iostream>
#include<string>
using namespace std;
string s[555],tmp,cur;
int ans,n,sz,pp;
bool f;
int main()
{
	ans=1e7;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	sz=s[1].size();
	for (int i=1;i<=sz;i++)
	{
		tmp=s[1].substr(1)+s[1][0];
		s[1]=tmp;
		if (i==sz) pp=0;
		else pp=i;
		for (int j=2;j<=n;j++)
		{
			cur=s[j];
			f=0;
			for (int k=1;k<=sz;k++)
			{
				if (cur==s[1]) 
				{
					f=1;
					break;
				}
				tmp=cur.substr(1)+cur[0]; 
				cur=tmp;
				pp++;
			}
			if (!f) pp+=1e7;
		}
		ans=min(ans,pp);
	}
	if (ans==1e7) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}