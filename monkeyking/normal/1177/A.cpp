#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
	ll k;
	cin>>k;
	int digit=1;
	int num=9;
	for(;;digit++,num*=10)
	{
		if(k-digit*num<=0) break;
		k-=digit*num;
	}
	int t=(k-1)/digit;
	ll x=num/9+t;
	char c[10000];
	itoa(x,c,10);
	cout<<c[(k-1)%digit]<<endl;
	return 0;
}