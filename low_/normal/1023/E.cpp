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
#define inf 9223372036854775799
#define mn 100005
#define FLN "test"

int n;
deque <char> dq1, dq2;

main()
{
//	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen(FLN".inp", "r", stdin);
//	freopen(FLN".out", "w", stdout);
	
	cin>>n;
	int curx=n, cury=n, tx, ty;
	string quer;
	while (curx+cury-2>=n)
	{
		if (curx==1 || cury==1) break;
		cout<<"? 1 1 "<<curx-1<<" "<<cury<<endl;
		cin>>quer;
		if (quer=="YES")
		{
			curx--;
			dq2.push_front('D');
	//		continue;
		}
		else
		{
			cury--;
			dq2.push_front('R');
		}
	}
	
	curx=1, cury=1;
	
	while (n+n-curx-cury>=n)
	{
		cout<<"? "<<curx<<" "<<cury+1<<" "<<n<<" "<<n<<endl;
		cin>>quer;
		if (quer=="YES")
		{
			cury++;
			dq1.push_back('R');
			continue;
		}
		
		curx++;
		dq1.push_back('D');
		
	}
	
	cout<<"! ";
	for (char c:dq1) cout<<c;for (char c:dq2) cout<<c;
	cout<<endl;
	exit(0);
	
	
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: