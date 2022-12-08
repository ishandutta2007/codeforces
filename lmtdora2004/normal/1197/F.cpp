/*
	With the aura of Dora chan, Accepted!
		
       .....           .....
   ,ad8PPPP88b,     ,d88PPPP8ba,
  d8P"      "Y8b, ,d8P"      "Y8b
 dP'           "8a8"           `Yd
 8(              "              )8
 I8                             8I
  Yb,                         ,dP
   "8a,                     ,a8"
     "8a,                 ,a8"
       "Yba             adP" 
         `Y8a         a8P'
           `88,     ,88'
             "8b   d8"
              "8b d8"
               `888'
                 "
*/

#include <bits/stdc++.h>
#define int long long
#define bug(x) cout<< #x << " = " << x << endl //chac la khong dung den dau
#define get tai_sao_toi_lai_rte_dit_cac

using namespace std;

int get[1005][5];
int n, dora;
int m[66][66][35];
pair<int, int> lim[1005][4];
int dp[65];
int mod = 998244353;
int a[1005];
vector<pair<int, int> > que[1005];
int ans[1005][5];
int f[5][5];

int gmex(vector<int> aa)
{
	int cnt[5];
//	cout<<"DEBUG MEX\n";
//	for(auto i:aa) cout<<i<<" ";
	memset(cnt, 0, sizeof(cnt));
	for(auto i:aa)
	{
		cnt[i]++;
	}
	for(int i=0; i<4; i++)
	{
		if(!cnt[i])
		{
//			cout<<endl<<i<<endl;
			return i;
		}
	}
}

int ghash(int i, int j, int k)
{
	return i+j*4+k*16;
}

void init()
{
	for(int i=0; i<=3; i++)
	{
		for(int j=0; j<=3; j++)
		{
			for(int k=0; k<=3; k++)
			{
				for(int d=1; d<=3; d++)
				{
					vector<int> cac={};
					if(f[d][1]) cac.push_back(i);
					if(f[d][2]) cac.push_back(j);
					if(f[d][3]) cac.push_back(k);
					m[ghash(gmex(cac),i,j)][ghash(i,j,k)][0]++;
				}
			}
		}
	}
	for(int bac=1; bac<=30; bac++)
	{
		for(int i=0; i<64; i++)
		{
			for(int j=0; j<64; j++)
			{
				for(int k=0; k<64; k++)
				{
					m[i][j][bac]+=m[i][k][bac-1]*m[k][j][bac-1];
					m[i][j][bac]%=mod;
				}
			}
		}
	}
}

void Dora(pair<int, int> col, int pos)
{
	int dp1[65];
	memset(dp1, 0, sizeof(dp1));
	for(int i=0; i<=3; i++)
	{
		for(int j=0; j<=3; j++)
		{
			for(int k=0; k<=3; k++)
			{
				for(int d=col.first; d<=col.second; d++)
				{
//					cout<<d<<"bug"<<endl;
					vector<int> cac={};
					if(f[d][1]&&pos>1) cac.push_back(i);
					if(f[d][2]&&pos>2) cac.push_back(j);
					if(f[d][3]&&pos>3) cac.push_back(k);
					dp1[ghash(gmex(cac),i,j)]+=dp[ghash(i,j,k)];
					dp1[ghash(gmex(cac),i,j)]%=mod;
				}
			}
		}
	}
	for(int i=0; i<64; i++)
	{
		dp[i]=dp1[i];
	}
}

void dangyeu(int bac)
{
//	bug(bac);
	int dp1[65];
	memset(dp1, 0, sizeof(dp1));
	for(int i=0; i<63; i++)
	{
		for(int j=0; j<63; j++)
		{
			dp1[i]+=dp[j]*m[i][j][bac];
			dp1[i]%=mod;
		}
	}
	for(int i=0; i<63; i++)
	{
		dp[i]=dp1[i];
	}
}

void dangyeu1()
{
	int dp1[65];
	memset(dp1, 0, sizeof(dp1));
	for(int i=0; i<63; i++)
	{
		for(int j=0; j<63; j++)
		{
			dp1[i]+=dp[j]*m[i][j][0];
			dp1[i]%=mod;
		}
	}
	for(int i=0; i<63; i++)
	{
		dp[i]=dp1[i];
	}
}

void mul(int dist)
{
//	for(int i=1; i<=dist; i++)
//	{
//		dangyeu1();
//	}
//	return;
	for(int i=0; i<=30; i++)
	{
		int lol=(1<<i);
		if((lol&dist)>0)
		{
			dangyeu(i);
		}
	}
}

void solve(int id)
{
	int cur=3;
	dp[0]=1;
	for(int i=1; i<=min(a[id], 3ll); i++)
	{
		Dora(lim[id][i], i);
	}
	for(auto i:que[id])
	{
		if(i.first<=3) continue;
		mul(i.first-1-cur);
		Dora({i.second,i.second}, i.first);
		cur=i.first;
	}
	if(cur<a[id]) mul(a[id]-cur);
}

signed main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		for(int j=1; j<=3; j++)
		{
			lim[i][j]={1,3};
		}
	}
	cin>>dora;
	for(int i=1; i<=dora; i++)
	{
		int t, p, c;
		cin>>t>>p>>c;
		if(p<=3)
		{
			lim[t][p]={c,c};
			continue;
		}
		que[t].push_back({p, c});
	}
	for(int i=1; i<=3; i++)
	{
		for(int j=1; j<=3; j++)
		{
			cin>>f[i][j];
		}
	}
//	cout<<"DEBUG1\n";
	init();
//	cout<<"OK1\n";
//	cout<<"DEBUG2\n";
	for(int ind=1; ind<=n; ind++)
	{
		sort(que[ind].begin(), que[ind].end());
		memset(dp, 0, sizeof(dp));
//		cout<<"DEBUG3\n";
//		bug(ind);
		solve(ind);
//		cout<<"OK3\n";
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				for(int k=0; k<4; k++)
				{
					get[ind][i]+=dp[ghash(i,j,k)];
					get[ind][i]%=mod;
				}
			}
		}
//		for(int i=0; i<=3; i++)
//		{
//			cout<<get[ind][i]<<endl;
//		}
	}
//	cout<<"OK2\n";
	ans[0][0]=1;
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<4; j++)
		{
			for(int k=0; k<4; k++)
			{
				ans[i][j^k]+=get[i][k]*ans[i-1][j];
				ans[i][j^k]%=mod;
			}
		}
	}
	cout<<(ans[n][0])%mod;
}