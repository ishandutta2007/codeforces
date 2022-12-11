#include <bits/stdc++.h>
typedef long long ll;

#define PB push_back
#define EB emplace_back 
#define MP make_pair 
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0); 
#define REP(i, a, b) for (int i = a; i < b; i++)


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const int INF = 1e9;

int main() {
	mipletsplay;
	int a,a1=0;
	cin >>a;
	int t=a;
	for (int i=0;i<6;i++)
	{
	  a1+=t%10;
	  t=t/10;
	}
	if (a1%4==0)
	cout<<a;
	else
	{
	 int a2=0,k=a+1;
	 for (int j=0;j<6;j++)
	{
	  a2+=k%10;
	  k=k/10;
	}
	if (a2%4==0)
	cout << a+1;
	else {
	int a3=0,f=a+2;
	 for (int s=0;s<6;s++)
	{
	  a3+=f%10;
	  f=f/10;
	}
	if (a3%4==0)
	cout << a+2;
	else {
	int a4=0,g=a+3;
	 for (int q=0;q<6;q++)
	{
	  a4+=g%10;
	  g=g/10;
	}
	if (a4%4==0)
	cout << a+3;
	else {
	int a5=0,c=a+4;
	 for (int w=0;w<6;w++)
	{
	  a5+=c%10;
	  c=c/10;
	}
	if (a5%4==0)
	cout << a+4;
	else{
	int a6=0,d=a+5;
	 for (int aa=0;aa<6;aa++)
	{
	  a6+=d%10;
	  d=d/10;
	}
	if (a6%4==0)
	cout << a+5;
	else {
	 int a7=0,z=a+6;
	 for (int aaa=0;aaa<6;aaa++)
	{
	  a7+=z%10;
	  z=z/10;
	}
	if (a7%4==0)
	cout << a+6;
	else {
	int a8=0,x=a+7;
	 for (int aaaa=0;aaaa<6;aaaa++)
	{
	  a8+=x%10;
	  x=x/10;
	}
	if (a8%4==0)
	cout << a+7;
	else {
	int a9=0,xx=a+8;
	 for (int aaaa=0;aaaa<6;aaaa++)
	{
	  a9+=xx%10;
	  xx=xx/10;
	}
	if (a8%4==0)
	cout << a+8;       
	    
	    
	    
	    
	    
	}
	    
	    
	    
	    
	    
	}
	    
	    
	    
	    
	    
	}
	    
	    
	    
	    
	    
	    
	}
	    
	    
	    
	    
	    
	}
	    
	    
	    
	    
	    
	}
	    
	    
	    
	    
	    
	 
	    
	    
	}
	   
	    
	    
	}
	
	
	
	}