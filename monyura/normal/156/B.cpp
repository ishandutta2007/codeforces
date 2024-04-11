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
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define x first
#define y second

const double PI=acos(-1.0);

int main()
{
	//vector<int> T[100001];
	//vector<int> F[100001];
	//int SayT[100001]={0};
	//int SayF[100001]={0};
	bool Can[100001]={0};
	int n,m;
	cin>>n>>m;
	int K[100001]={0};
	int NK[100001]={0};
	int tNK=0;
	int A[100001];
	rep(i,0,n)
	{
		int a;
		scanf("%d",&a);
		A[i]=a;
		if (a<0)
		{
			//F[-a-1].push_back(i);
			NK[-a-1]++;
			tNK++;
		}
		else
		{
			//T[a-1].push_back(i);
			K[a-1]++;
		}
	}
	int cnt=0;
	rep(i,0,n)
		if (K[i]+tNK-NK[i]==m)
		{
			Can[i]=1;
			cnt++;
			/*rep(j,0,T[i].size())
			{
				SayT[T[i][j]]++;
				SayF[T[i][j]]--;
			}*/
		}
	rep(i,0,n)
		if (cnt==1 && A[i]>0 && Can[A[i]-1] || A[i]<0 && !Can[-A[i]-1])
			printf("Truth\n");
		else if (A[i]>0 && !Can[A[i]-1] || cnt==1 && A[i]<0 && Can[-A[i]-1])
			printf("Lie\n");
		else
			printf("Not defined\n");
	return 0;
} 

/*
cb
bda


*/