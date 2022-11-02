//#pragma comment(linker,"/STACK:128000000")
#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<short,short> pss;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

char S[100100];
char Sep[1001];

vector<string> split(string str,string sep)
{
	//char *S=new char[str.size()+2];
	//char *Sep=new char[sep.size()+2];	
	strcpy(S,str.c_str());
	strcpy(Sep,sep.c_str());
	vector<string> res;
	for (char *curr=strtok(S,Sep);curr;curr=strtok(0,Sep))
		if (curr[0]!=0)
			res.push_back(curr);
	//delete []S;
	//delete []Sep;
	return res;
}

void run()
{
	int n;
	cin>>n;
	cin.get();
	char str[100100];
	vector<int> V[1001];
	vector<string> vec;
	string Arr[]={"int","string","double","T"};
	map<string,int> mp;
	rep(i,0,4)
		mp[Arr[i]]=i;
	string Fname[1001];
	rep(i,0,n)
	{
		gets(str);
		vec=split(str,"() ,");
		Fname[i]=vec[1];
		rep(j,2,vec.size())
			V[i].push_back(mp[vec[j]]);
	}
	map<string,int> var;
	int m;
	cin>>m;
	char name[1001];
	rep(i,0,m)
	{
		scanf(" %s %s",str,name);
		var[name]=mp[str];
	}
	int k;
	cin>>k;
	cin.get();
	rep(i,0,k)
	{
		gets(str);
		vec=split(str,"() ,");
		vector<int> curr;
		rep(j,1,vec.size())
			curr.push_back(var[vec[j]]);
		int res=0;
		rep(j,0,n)
			if (Fname[j]==vec[0] && curr.size()==V[j].size())
			{
				bool ok=true;
				rep(l,0,curr.size())
					if (curr[l]!=V[j][l] && V[j][l]!=3)
					{
						ok=false;
						break;
					}
				res+=ok;
			}
		printf("%d\n",res);
	}
}

int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t beg=clock();
#endif
	run();
#ifdef _MONYURA_
	printf("================\n");
	printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
	return 0;
}

/*

*/