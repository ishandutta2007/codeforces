#include <bits/stdc++.h>

using namespace std;

int n, q;
string s;

int last[100005][40];
int dp[255][255][255];
char ok[255][5];

int glast(int i, int j, int k, char take)
{
	if(i<0||j<0||k<0) return n+1;
	return last[dp[i][j][k]][(int)take];
}

signed main()
{
	cin>>n>>q>>s;
	s='!'+s+'a';
	for(int i=0; i<26; i++)
	{
		last[n+1][i]=n+1;
	}
	for(int i=n; i>=0; i--)
	{
		for(int j=0; j<26; j++)
		{
			last[i][j]=last[i+1][j];
		}
		last[i][s[i+1]-'a']=i+1;
	}
	int l1=0, l2=0, l3=0;
	for(int i=1; i<=q; i++)
	{
		string check;
		cin>>check;
		if(check=="+")
		{
			int pos;
			cin>>pos>>check;
			if(pos==1)
			{
				l1++;
				ok[l1][1]=check[0]-'a';
				for(int i=0; i<=l2; i++)
				{
					for(int j=0; j<=l3; j++)
					{
						dp[l1][i][j]=min(glast(l1-1, i, j, ok[l1][1]), min(glast(l1, i-1, j, ok[i][2]), glast(l1, i, j-1, ok[j][3])));
					}
				}
			}
			else if(pos==2)
			{
				l2++;
				ok[l2][2]=check[0]-'a';
				for(int i=0; i<=l1; i++)
				{
					for(int j=0; j<=l3; j++)
					{
						dp[i][l2][j]=min(glast(i-1, l2, j, ok[i][1]), min(glast(i, l2-1, j, ok[l2][2]), glast(i, l2, j-1, ok[j][3])));
					}
				}
			}
			else if(pos==3)
			{
				l3++;
				ok[l3][3]=check[0]-'a';
				for(int i=0; i<=l1; i++)
				{
					for(int j=0; j<=l2; j++)
					{
						dp[i][j][l3]=min(glast(i-1, j, l3, ok[i][1]), min(glast(i, j-1, l3, ok[j][2]), glast(i, j, l3-1, ok[l3][3])));
					}
				}
			}
		}
		else
		{
			int pos;
			cin>>pos;
			if(pos==1) l1--;
			else if(pos==2) l2--;
			else l3--;
		}
		if(dp[l1][l2][l3]<=n) cout<<"YES\n";
		else cout<<"NO\n";
	}
}