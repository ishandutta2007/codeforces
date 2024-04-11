#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define ST first
#define ND second
#define MP make_pair

using namespace std;

typedef long long int lld;
typedef pair<int,int> pi;
const int MAXN = 100010;

vector<string> Ans, v;
string s, tt;

int main () 
{
	getline(cin, s);
	for (int i=0; i<s.size(); i++)
		if(s[i] == ',') v.pb(",");
		else if(s[i] == '.') v.pb("..."), i += 2;
		else if(s[i] == ' ');
		else 
		{
			tt = "";
			for (i; i < s.size() && s[i] >= '0' && s[i] <= '9'; i ++) tt += s[i];
			v.pb(tt);
			i --;
		}
	for (int i = 0; i < v.size(); i ++)
		if (v[i] == "...") 
		{
			if (Ans.size() > 0 && Ans.back() != " ")
				Ans.pb(" ");
			Ans.pb(v[i]);
		}
		else if (v[i] == ",") 
		{
			Ans.pb(v[i]);
			if (i != (int)v.size() - 1) Ans.pb(" ");
		}
		else 
		{
			if (Ans.size() > 0 && Ans.back()[0] >= '0' && Ans.back()[0] <= '9') Ans.pb(" ");
			Ans.pb(v[i]);
		}
	for (int i = 0; i < Ans.size(); i ++)
		cout << Ans[i];
	return 0;
}