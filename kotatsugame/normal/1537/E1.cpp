#line 1 "a.cpp"
#include<iostream>
using namespace std;
#line 1 "/home/kotatsugame/library/string/Zalgo.cpp"
//Longest Common Prefix(s,s.substr(i)) O(|s|)
#include<vector>
#include<string>
vector<int>Zalgo(const string&s)
{
	vector<int>ret(s.size());
	if(s.empty())return ret;
	ret[0]=s.size();
	int i=1,j=0;
	while(i<s.size())
	{
		while(i+j<s.size()&&s[j]==s[i+j])j++;
		ret[i]=j;
		if(j==0)
		{
			i++;
			continue;
		}
		int k=1;
		while(i+k<s.size()&&k+ret[k]<j)ret[i+k]=ret[k],k++;
		i+=k;j-=k;
	}
	return ret;
}
#line 4 "a.cpp"
int N,K;
string S;
main()
{
	cin>>N>>K>>S;
	vector<int>A=Zalgo(S);
	int mi=1;
	for(int i=2;i<=N;i++)
	{
		if(A[mi]<i-mi)
		{
			if(S[A[mi]]>S[mi+A[mi]])mi=i;
		}
		else
		{
			if(A[i-mi]<mi)
			{
				if(S[i-mi+A[i-mi]]>S[A[i-mi]])mi=i;
			}
		}
	}
	S=S.substr(0,mi);
	while(K>=mi)
	{
		K-=mi;
		cout<<S;
	}
	cout<<S.substr(0,K)<<endl;
}