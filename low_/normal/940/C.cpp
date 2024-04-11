#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
#define mod 1000000007
#define inf 9223372036854775799
#define mn 100005

vector <char> Vtong;
int ltr[26];

class NumBase{
public: 
	int BASE;
	deque <int> DQ;
	
	void Init(string S, int b)
	{
		BASE=b;
		for (int i=0; i<S.size(); i++) DQ.push_back(ltr[S[i]-97]-1);
	}
	
	void add_1()
	{
		int i1=DQ.size()-1;
		DQ[i1]++;
		while (i1>=0)
		{
			if (DQ[i1]<BASE) break;
			
			DQ[i1]=0;
			if (i1==0)
			{
				DQ.push_back(1);
				break;
			}
			else 
			{
				i1--;
				DQ[i1]++;
			}
		}
	}
	void print()
	{
		for (int i=0; i<DQ.size(); i++) cout<<Vtong[DQ[i]];
	}
};

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int l1, l2, BS=0;
	string S;
	cin>>l1>>l2>>S;
	
	for (int i=0; i<26; i++) ltr[i]=0;
	for (int i=0; i<l1; i++) ltr[S[i]-97]=1;
	for (int i=0; i<26; i++) if (ltr[i]==1)
	{
		BS++;
		ltr[i]=BS;
		Vtong.push_back(i+97);
	}
	
	if (BS==1) 
	{
		for (int i=0; i<l2; i++) cout<<S[0];
		return 0;
	}
	
	NumBase NB;
	if (l2<=l1) 
	{
		NB.Init(S.substr(0, l2), BS);
		NB.add_1();
		NB.print();
	}
	else
	{
		cout<<S;
		for (int i=0; i<l2-l1; i++) cout<<Vtong[0];
	}
	
}