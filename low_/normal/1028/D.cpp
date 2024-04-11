#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 1000000009
#define mn 100005
#define mod 1000000007
#define FLN "test"

priority_queue <int> sure_sell, sure_buy;
int ans=1;
vector <int> waitline;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	sure_sell.push(-inf);
	sure_buy.push(0);
	int n, p;
	string s;
	cin>>n;
	for (int i=1; i<=n; i++)
	{
		cin>>s>>p;
		if (s=="ADD")
		{
			if (p>sure_buy.top() && p<-sure_sell.top()) waitline.push_back(p);
			else if (p<=sure_buy.top()) sure_buy.push(p);
			else if (p>=-sure_sell.top()) sure_sell.push(-p);
		}
		else
		{
			if (p>sure_buy.top() && p<-sure_sell.top())
			{
				sort(waitline.begin(), waitline.end());
				while (!waitline.empty())
				{
					if (waitline.back()==p) break;
					sure_sell.push(-waitline.back());
					waitline.pop_back();
				}
				ans=(ans*2)%mod;
				waitline.pop_back();
				while (!waitline.empty())
				{
					sure_buy.push(waitline.back());
					waitline.pop_back();
				}
			}
			else if (p==sure_buy.top()) 
			{
				while (!waitline.empty())
				{
					sure_sell.push(-waitline.back());
					waitline.pop_back();
				}
				sure_buy.pop();
			}
			else if (p==-sure_sell.top()) 
			{
				while (!waitline.empty())
				{
					sure_buy.push(waitline.back());
					waitline.pop_back();
				}
				sure_sell.pop();
			}
			else 
			{
				cout<<0;
				return 0;
			}
		}
	}
	ans=(ans*(waitline.size()+1))%mod;
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: