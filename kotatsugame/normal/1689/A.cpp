#include<iostream>
using namespace std;
int T,N,M,K;
int cA[26],cB[26];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M>>K;
		for(int i=0;i<26;i++)cA[i]=cB[i]=0;
		{
			string A;
			cin>>A;
			for(char c:A)cA[c-'a']++;
		}
		{
			string A;
			cin>>A;
			for(char c:A)cB[c-'a']++;
		}
		string C="";
		int iA=0,iB=0;
		int rep=0;
		while(N&&M)
		{
			while(cA[iA]==0)iA++;
			while(cB[iB]==0)iB++;
			bool fA;
			if(abs(rep)<K)
			{
				if(iA<iB)
				{
					C+=iA+'a';
					cA[iA]--;
					N--;
					fA=true;
				}
				else
				{
					C+=iB+'a';
					cB[iB]--;
					M--;
					fA=false;
				}
			}
			else
			{
				if(rep==K)
				{
					C+=iB+'a';
					cB[iB]--;
					M--;
					fA=false;
				}
				else
				{
					C+=iA+'a';
					cA[iA]--;
					N--;
					fA=true;
				}
			}
			if(fA)
			{
				if(rep>=0)rep++;
				else rep=1;
			}
			else
			{
				if(rep<=0)rep--;
				else rep=-1;
			}
		}
		cout<<C<<"\n";
	}
}