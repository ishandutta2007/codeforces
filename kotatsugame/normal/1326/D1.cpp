#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
#include<string>
vector<int>manacher(const string&s)
{
	vector<int>ret(s.size());
	int i=0,j=0;
	while(i<s.size())
	{
		while(i-j>=0&&i+j<s.size()&&s[i-j]==s[i+j])j++;
		ret[i]=j;
		int k=1;
		while(i-k>=0&&i+k<s.size()&&k+ret[i-k]<j)ret[i+k]=ret[i-k],k++;
		i+=k;j-=k;
	}
	return ret;
}
int T;
main()
{
	cin>>T;
	for(;T--;)
	{
		string S;cin>>S;
		string ss="";
		for(int i=0;i<S.size();i++)
		{
			ss+='$';
			ss+=S[i];
		}
		ss+='$';
		vector<int>R=manacher(ss);
		int ac=0;
		pair<int,int>lr;
		for(int i=0;i*2<=S.size();i++)
		{
			if(i>0&&S[i-1]!=S[S.size()-i])break;
			if(ac<i*2)
			{
				ac=i*2;
				lr=make_pair(i,i);
			}
			for(int j=i;j<S.size()-i;j++)
			{
				{
					int wd=min(j-i+1,(int)S.size()-i-j);
					if(R[j*2+1]>=wd*2)
					{
						if(ac<i*2+wd*2-1)
						{
							ac=i*2+wd*2-1;
							if(j-i+1<S.size()-i-j)lr=make_pair(i+wd*2-1,i);
							else lr=make_pair(i,i+wd*2-1);
						}
					}
				}
				if(j+1<S.size()-i)
				{
					int wd=min(j-i+1,(int)S.size()-i-j-1);
					if(R[j*2+2]>=wd*2)
					{
						if(ac<i*2+wd*2)
						{
							ac=i*2+wd*2;
							if(j-i+1<S.size()-i-j-1)lr=make_pair(i+wd*2,i);
							else lr=make_pair(i,i+wd*2);
						}
					}
				}
			}
		}
		string ans="";
		for(int i=0;i<lr.first;i++)ans+=S[i];
		for(int i=lr.second;i--;)ans+=S[S.size()-1-i];
		cout<<ans<<endl;
	}
}