#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <memory>
#include <memory.h>
#include <set>
#include <map>
#include <vector>
#include <time.h>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>

using namespace std;

typedef long long li;
typedef long double ld;
typedef vector <int> vi;
typedef pair <int, int> pi;
#define pb push_back
#define mp make_pair

vector<vector<pi > > g;

int main()
{
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
#endif
	int a,b,c;
	cin>>a>>b>>c;
	int q,w,e;
	cin>>q>>w>>e;
	if(a==q || w==b || c==e)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}