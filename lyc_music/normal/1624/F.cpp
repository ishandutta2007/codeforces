// Lynkcat.
// Problem: F. Interacdive Problem
// URL: https://codeforces.com/contest/1624/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// -----------------------------------------------

//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
//#define int ll
//#define N
using namespace std;
int n;
inline int Ask(int x){
	cout<<"+ "<<x<<endl;
	cin>>x;
	return x;
}
void Report(int x){
	cout<<"! "<<x<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int t=0;
	int o=1;
	while((o<<1)<n)o<<=1;
	int las=0;
	while(o>=1){
		int nt=Ask(o+las);
		if(nt^t)las=n-o;
		else las=0;
		t=nt;
		o>>=1;
	}
	if(las)Report(n*t);
	else Report(n*(t+1)-1);
	return 0;
}