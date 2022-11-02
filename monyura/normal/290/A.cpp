//#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
//#endif

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;	
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double PI = acos(-1.0);

vector<string> split(string str,string sep)
{
	char *S=new char[str.size()+2];
	char *Sep=new char[sep.size()+2];
	strcpy(S,str.c_str());
	strcpy(Sep,sep.c_str());
	vector<string> res;
	for (char *curr=strtok(S,Sep);curr;curr=strtok(0,Sep))
		res.push_back(curr);
	delete []S;
	delete []Sep;
	return res;
}

void go()
{
	char Ans[50][50]={"Washington",
		"Adams",
"Jefferson",
"Madison",
"Monroe",
"Adams",
"Jackson",
"Van Buren",
"Harrison",//"Henry Harrison",
"Tyler",
"Polk",
"Taylor",
"Fillmore",
"Pierce",
"Buchanan",
"Lincoln",
"Johnson",
"Grant",
"Hayes",
"Garfield",
"Arthur",
"Cleveland",
"Harrison",
"Cleveland",
"McKinley",
"Roosevelt",
"Taft",
"Wilson",
"Harding",
"Coolidge",
"Hoover",
"Roosevelt",
"Truman",
"Eisenhower",
"Kennedy",
"Johnson",
"Nixon",
"Ford",
"Carter",
"Reagan"};
	int i;
	cin>>i;
	cout<<Ans[i-1]<<endl;
}


void run()
{
	/*typedef pair<int,string> pis;
	char str[100];
	vector<pis> A;
	while (1)
	{
		int a;
		if (scanf("%d",&a)!=1) 
			break;
		gets(str);
		vector<string> v = split(str," \n\t.");
		string res = "";
		if (v.size()==2)
			res = v.back();
		else
		{
			if (v[1].size()>1)
			{
				res = v[1]+" "+v[2];
			}
			else
				res = v[2];
		}
		A.push_back(pis(a,res));
	}
	sort(all(A));
	rep(i,0,40)
		printf("%d ",A[i].first);
	rep(i,0,40)
		printf("\"%s\",\n",A[i].second.c_str());*/
	go();
	
}





int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);	
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf( "=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
3
abcdefghABCDEFGH
3
abc
a
abAB
xyz
1
xyz
abacaba
6
a
aba
caba 
acaba
ba
bacb
*/