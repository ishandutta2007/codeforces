#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 1e2+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int t1 , t2;
double hh , mm , ss , h , m , s;

int main ()
{
	int i , j;
	scanf("%lf%lf%lf%d%d",&h,&m,&s,&t1,&t2);
	ss = s;
	if (ss >= 60) ss -= 60;
	mm = m+(ss/60);
	if (mm >= 60) mm -= 60;
	hh = h+(mm/60);
	if (hh >= 12) hh -= 12;
	mm /= 5;
	ss /= 5;
	if (t1 >= 12) t1 -= 12;
	if (t2 >= 12) t2 -= 12;
	if (t1 > t2) swap(t1,t2);
	int c = 0;
	if (t1 < hh && hh < t2 && t1 < mm && mm < t2 && t1 < ss && ss < t2) c = 1;
	if ((t1 > hh || hh > t2) && (t1 > mm || mm > t2) && (t1 > ss || ss > t2)) c = 1;
	if (c) cout << "YES\n";
	else cout << "NO\n"; 
	//system("PAUSE");
	return 0;
}