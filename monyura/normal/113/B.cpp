#pragma comment(linker,"/STACK:64000000")
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
typedef short int si;
typedef long double ld;
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) x.begin(),x.end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

char S[5000]={0};
int P[5001];
vector<int> KMP(char *s1,char *s2)
{
	strcpy(S,s1);
	strcat(S,"#");
	strcat(S,s2);
	P[0]=0;
	int n=strlen(s1);
	vector<int> vec;
	for (int i=1;S[i];i++)
	{
		int curr=P[i-1];
		while (curr>0 && S[curr]!=S[i])
			curr=P[curr-1];
		if (S[curr]!=S[i])
			P[i]=0;
		else
			P[i]=curr+1;
		if (P[i]==n) vec.push_back(i-2*n);
	}
	return vec;
}

int H1[2001][2001];
int A1=23716;
int H2[2001][2001];
int A2=A1;
int M=1e9+7;
void hash(char *str)
{
	int n=strlen(str);
	rep(i,0,n)
	{
		H2[i][i]=H1[i][i]=str[i];
		rep(j,i+1,n)
		{
			H1[i][j]=ll(H1[i][j-1])*5+str[j];
			H2[i][j]=(ll(H2[i][j-1])*A2+str[j])%M;
		}
	}
}


int main()
{
	/*freopen("test.txt","w",stdout);
	rep(i,0,1000) putchar('a');
	rep(i,0,1000) putchar('b');
	printf("\na\nb\n");
	return 0;*/
	//freopen("test.txt","r",stdin);
	time_t beg=clock();
	char str[2001];
	char sbeg[2001];
	char send[2001];
	scanf(" %s %s %s",str,sbeg,send);
	hash(str);
	int lbeg=strlen(sbeg);
	int lend=strlen(send);
	vector<int> p1=KMP(sbeg,str);
	vector<int> p2=KMP(send,str);
	rep(i,0,p2.size())
		p2[i]+=lend-1;
	int cnt=0;
	//set<pii> st;
	//set<int> st;
	vector<pii> vec;
	rep(i,0,p1.size())
		rep(j,0,p2.size())
			if (p2[j]-p1[i]+1>=lbeg && p2[j]-p1[i]+1>=lend)
				vec.push_back(pii(H2[p1[i]][p2[j]],p2[j]-p1[i]));
	sort(all(vec));
	cout<<unique(all(vec))-vec.begin()<<endl;
//	printf("%.2lf\n",(clock()-beg)/double(CLOCKS_PER_SEC));
	return 0;
}


/*

*/