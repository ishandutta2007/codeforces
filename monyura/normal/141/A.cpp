//#pragma comment(linker,"/STACK:32000000")
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

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}


int main()
{
	char S[202],B[202];
	scanf("%s",S);
	int n=strlen(S);
	scanf(" %s",S+n);
	n=strlen(S);
	scanf(" %s",B);
	int m=strlen(B);
	sort(S,S+n);
	sort(B,B+n);
	if (strcmp(S,B)==0)
		puts("YES");
	else
		puts("NO");
	return 0;
} 

/*
4 4
1 2 -10 3
1 3 1 -10
2 4 -10 -4
3 4 0 -3
*/