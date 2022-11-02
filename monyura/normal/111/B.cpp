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

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}


int main()
{
	//freopen("test.txt","w",stdout);
	//cout<<100000<<endl;
	//rep(i,0,100000)
	//	printf("%d %d\n",i+1,i);
	//return 0;
	//freopen("test.txt","r",stdin);
	//freopen("test.out","w",stdout);
	//time_t beg=clock();
	int n;
	cin>>n;
	vector<int> *vec=new vector<int>[100001];
	int del;
	rep(i,0,n)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int j;
		int res=0;
		for (j=1;j*j<a;j++)
		{
			if (a%j==0) 
			{
				del=a/j;
				if (lower_bound(vec[j].begin(),vec[j].end(),i-b)==vec[j].end())
					res++;
				if (lower_bound(vec[del].begin(),vec[del].end(),i-b)==vec[del].end())
					res++;
				vec[j].push_back(i);
				vec[del].push_back(i);
			}
		}
		if (j*j==a)
		{
			if (lower_bound(vec[j].begin(),vec[j].end(),i-b)==vec[j].end())
					res++;
			vec[j].push_back(i);
		}
		printf("%d\n",res);
	}
	//fprintf(stderr,"Time: %.2lf\n",(clock()-beg)/double(CLOCKS_PER_SEC));
	return 0;
}


/*




*/