#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <assert.h>
#include <bitset>
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsinged long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
const int inf=1039074182;
using namespace std;
int n;
vector <int> oddPos;
vector <int> oddNeg;
vector <int> vEven;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	int x;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(x%2==0) vEven.push_back(x);else if(x>0) oddPos.push_back(x);else oddNeg.push_back(-x);
	}
	int res=0;
	sort(all(oddPos));
	reverse(all(oddPos));
	sort(all(oddNeg));
	if(~(int)oddPos.size()&1)
	{
		if(oddPos.size()>0 && (oddNeg.size()==0 || oddPos.back()<oddNeg[0])) oddPos.pop_back();
		else oddPos.push_back(-oddNeg[0]);
	}
	for(auto x:oddPos) res+=x;
	for(auto x:vEven) if(x>0) res+=x;
	cout<<res<<endl;
	return 0;
}