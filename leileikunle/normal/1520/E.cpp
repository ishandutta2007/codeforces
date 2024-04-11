#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define for00 for(int i=1;i<=n;i++) cin>>a[i];
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
using namespace std;
const int N = 1e6+10;
char a[N];
void solve()
{
	memset(a,0,sizeof a);
	int n; cin>>n;
	int sum = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]=='*') sum++;
	}
	if(sum%2==0)
	{
		int q = 0,w = 0,cnt = 0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='*') cnt++;
			if(cnt==(sum/2)) q=i;
			if(cnt==(sum/2+1)) w=i;
		}
		int m1=0,m2=0;
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='*')
			{
				cnt++;
				if(cnt<=sum/2)
				{
					int t = abs(sum/2-cnt);
					m1+=abs(q-t-i);
				}else{
					int t = abs(cnt-sum/2);
					m1+=abs(i-(q+t));
				}
				
			}
		}
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='*')
			{
				cnt++;
				if(cnt<=(sum/2+1))
				{
					int t = abs(sum/2+1-cnt);
					m2+=abs(w-t-i);
				}else{
					int t = abs(cnt-sum/2-1);
					m2+=abs(i-(w+t));
				}
				
			}
		}
		cout<<min(m1,m2)<<endl;
		return;
	}else{
		
		int q = 0,cnt = 0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='*') cnt++;
			if(cnt==(sum/2+1)) 
			{
				q=i;
				break;
			}
		}
//		cout<<"q: "<<q<<endl; 
		int m = 0;
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='*')
			{
				cnt++;
				if(cnt<=(sum/2+1))
				{
					int t = abs(sum/2+1-cnt);
					m+=abs(q-t-i);
//					cout<<"zuo m :"<<m<<endl;
				}else{
					int t = abs(cnt-sum/2-1);
					m+=abs(i-(q+t));
//					cout<<"you m :"<<m<<endl;
				}
				
			}
		}
		cout<<m<<endl;
	}
	
}
signed main()
{
	ios;
	int tt = 1;
	cin>>tt;
	while(tt--)
	{
		solve();
	}
}