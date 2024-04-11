/*
*/

//#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 100031;

int n;
double ar1[N], ar2[N], ans1[N], ans2[N], pref1[N], pref2[N], suf1[N], suf2[N];
double res1,res2;
pair<double, double> ans[N];

pair<double, double> solve(double a, double b)
{
	if (fabs(a) < eps)
	{
		return make_pair(0, b);
	}

	//cout << a << "%" << b << endl;
	//x*y=a
	//x+y=b;
	//y=b-x
	//x*(b - x) = a;
	//x*b-x*x-a=0;
	//x*x-x*b+a=0
	//d=b*b-4*a
	double D = b*b - 4 * a;
	if (D < 0) D = 0;
	D = sqrt(D);
	double X = b + D;
	X /= 2;
	double Y = a / X;
	if (Y > X)
		swap(X, Y);
	return make_pair(X, Y);
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf", &ar1[i]);
		//cin >> ar1[i];
	}
	for (int i = 1; i <= n; i++)
	{
//		cin >> ar2[i];
		scanf("%lf", &ar2[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		pref1[i] = pref1[i - 1] + ar1[i];
		pref2[i] = pref2[i - 1] + ar2[i];
	}

	for (int i = n; i; --i)
	{
		suf1[i] = suf1[i + 1] + ar1[i];
		suf2[i] = suf2[i + 1] + ar2[i];
	}

	for (int i = n; i; --i)
	{
		res1 = suf2[i];
		res2 = suf1[i] + suf2[i];
		//res2 += res1;

		ans[i] = solve(res1, res2);
	}

	for (int i = n; i; --i)
	{
		ans1[i] = ans[i].first - ans[i + 1].first;
		ans2[i] = ans[i].second - ans[i + 1].second;
	}

	cout.precision(10);

	for (int i = 1; i <= n; i++)
	{
	    if (ans1[i] < 0) ans1[i] = 0;
		if (i > 1)
			printf(" ");
		printf("%.10lf", ans1[i]);
//		cout << fixed<<ans1[i];
	}
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
	    if (ans2[i] < 0) ans2[i] = 0;
		if (i > 1)
			printf(" ");
		printf("%.10lf", ans2[i]);
//		cout << fixed << ans2[i];
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}