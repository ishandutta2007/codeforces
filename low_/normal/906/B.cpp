#include<iostream>
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

int m, n;

main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	deque <int> fst;
	
	cin>>n>>m;
	
	if (m==1 && n==1) cout<<"YES\n1";
	else if (max(m, n)<4) 
	{
		if (m==3 && n==3) cout<<"YES\n5 1 6\n7 3 8\n9 4 2";
		else cout<<"NO";
	}
	else
	{
		if (m>=n || m>3)
		{
			fst={3, 1, 4, 2};
			
			while (fst.size()<m)
			{
				if (fst.size()%2==0) fst.push_front(fst.size()+1);
				else fst.push_back(fst.size()+1);
			}
			
			cout<<"YES\n";
			if (m%2==0)
			{
				for (int i=0; i<n; i++) 
				{
					reverse(fst.begin(), fst.end());
					for (int i=0; i<m; i++) 
					{
						cout<<fst[i]<<" ";
						fst[i]=fst[i]+m;
					}
					cout<<"\n";
				}
			}
			else
			{
				int h=m/2;
				for (int i=0; i<n; i++)
				{
					if (i%2==0)
					{
						reverse(fst.begin(), fst.end());
						
						fst[0]+=fst[h];
						fst[h]=fst[0]-fst[h];
						fst[0]-=fst[h];
						
					//	cerr<<fst[0]<<" "<<fst[h]<<"\n";
						
						for (int i=0; i<m; i++) 
						{
							cout<<fst[i]<<" ";
							fst[i]+=m;
						}
					}
					else
					{
						fst[0]+=fst[h];
						fst[h]=fst[0]-fst[h];
						fst[0]-=fst[h];
						
					//	cerr<<fst[0]<<" "<<fst[h]<<"\n";
						
						reverse(fst.begin(), fst.end());
						for (int i=0; i<m; i++) 
						{
							cout<<fst[i]<<" ";
							fst[i]+=m;
						}
					}
					cout<<"\n";
				}
			}
		}
		else
		{
			fst={2*m+1, 1, 3*m+1, m+1};
			
			while (fst.size()<n)
			{
				if (fst.size()%2==0) fst.push_front(fst.size()*m+1);
				else fst.push_back(fst.size()*m+1);
			}
			
			vector <deque <int> > V;
			
			cout<<"YES\n";
			if (n%2==0)
			{
				for (int i=0; i<m; i++) 
				{
					reverse(fst.begin(), fst.end());
					V.push_back(fst);
					for (int i=0; i<n; i++) fst[i]++;
				}
			}
			else
			{
				int h=n/2;
				for (int i=0; i<m; i++)
				{
					if (i%2==0)
					{
						reverse(fst.begin(), fst.end());
						
						fst[0]+=fst[h];
						fst[h]=fst[0]-fst[h];
						fst[0]-=fst[h];
						V.push_back(fst);
						for (int i=0; i<n; i++) fst[i]++;
					}
					else
					{
						fst[0]+=fst[h];
						fst[h]=fst[0]-fst[h];
						fst[0]-=fst[h];
						
						reverse(fst.begin(), fst.end());
						V.push_back(fst);
						for (int i=0; i<n; i++) fst[i]++;
					}
				}
			}
			
			for (int i=0; i<n; i++)
			{
				for (int j=0; j<m; j++) cout<<V[j][i]<<" ";
				cout<<"\n";
			}
		}
	}
}