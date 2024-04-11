#include <bits/stdc++.h>
using namespace std;
void print(string s){cout<<s<<endl;}
string input(){string s;cin>>s;return s;}
unsigned long long len(string s){return s.size();}
int main()
{
	function<long long(string)> toInt=[&](string s)->long long
	{
		long long __B1;
		{
			long long res=(0);
			unsigned long long size=((len)(s));
			for(long long i=(0); (i)<(unsigned long long)(size); (i)++)
			{
				(res)*=(long long)(10);
				(res)+=(char)(((s)[i])-(char)('0'));
			}
			__B1=(res);
		}
		return __B1;
	};
	function<string(string)> rev=[&](string s)->string
	{
		string __B3;
		{
			string res=(string(""));
			unsigned long long size=((len)(s));
			for(long long i=((size)-(long long)(1)); (i)>=(long long)(0); (i)--)
			{
				(res)+=(char)((s)[i]);
			}
			__B3=(res);
		}
		return __B3;
	};
	function<string(unsigned long long)> toStr=[&](unsigned long long x)->string
	{
		string __B5;
		{
			string res=(string(""));
			if((x)==(long long)(0))
			{
				return string("0");
			}
			while(!((x)==(long long)(0)))
			{
				{
					unsigned long long rem=((x)%(long long)(10));
					(res)+=(char)(('0')+(unsigned long long)(rem));
					(x)/=(long long)(10);
				}
			}
			__B5=((rev)(res));
		}
		return __B5;
	};
	function<long long()> in=[&]()->long long
	{
		long long __B10;
		{
			__B10=((toInt)((input)()));
		}
		return __B10;
	};
	function<void(long long)> out=[&](long long x)->void
	{
		{
			(print)((toStr)(x));
		}
	};
	array<int,500000> a;
	long long t=((in)());
	for(long long i=(0); (i)<(long long)(t); (i)++)
	{
		long long n=((in)());
		for(long long j=(0); (j)<(long long)(n); (j)++)
		{
			((a)[j])=(long long)((((j)+(long long)(1))%(long long)(n))+(long long)(1));
		}
		string line=(string(""));
		bool first=(true);
		for(long long j=(0); (j)<(long long)(n); (j)++)
		{
			if(!(first))
			{
				(line)+=(string)(string(" "));
			}
			(line)+=(string)((toStr)((a)[j]));
			(first)=(bool)(false);
		}
		(print)(line);
	}
}