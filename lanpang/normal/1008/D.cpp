#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5+10;
const LL mod = 1e9+7;

int n , A , B , C , du[maxn];
LL s[8] , u[8] , a , b , c , ab , ac , bc , abc , ans , tk , ch[8][8][8];

LL cnt(LL x , LL y)
{
	LL ret = 1;
	for (LL i = 1 ; i <= y ; i++)
		ret = ret*(x-i+1)/i;
	return ret;
}

bool check(int x , int y , int z)
{
	if ((x&1) && (y&2) && (z&4)) return true;
	if ((x&1) && (y&4) && (z&2)) return true;
	if ((x&2) && (y&1) && (z&4)) return true;
	if ((x&2) && (y&4) && (z&1)) return true;
	if ((x&4) && (y&1) && (z&2)) return true;
	if ((x&4) && (y&2) && (z&1)) return true;
	return false;
}

int main()
{
	int i , j , k;
	for (i = 1 ; i <= 100000 ; i++)
		for (j = i ; j <= 100000 ; j += i)
			du[j]++;
	for (i = 1 ; i <= 7 ; i++)
		for (j = i ; j <= 7 ; j++)
			for (k = j ; k <= 7 ; k++)
				ch[i][j][k] = check(i,j,k);
	cin >> n;
	while (n--)
	{
		scanf("%d%d%d",&A,&B,&C);
		a = du[A];
		b = du[B];
		c = du[C];
		ab = du[__gcd(A,B)];
		ac = du[__gcd(A,C)];
		bc = du[__gcd(B,C)];
		abc = du[__gcd(A,__gcd(B,C))];
		ab -= abc;
		ac -= abc;
		bc -= abc;
		a -= ab+ac+abc;
		b -= ab+bc+abc;
		c -= ac+bc+abc;
		s[1] = a;
		s[2] = b;
		s[4] = c;
		s[3] = ab;
		s[5] = ac;
		s[6] = bc;
		s[7] = abc;
		ans = 0;
		for (i = 1 ; i <= 7 ; i++)
			for (j = i ; j <= 7 ; j++)
				for (k = j ; k <= 7 ; k++)
					if (ch[i][j][k] && s[i] && s[j] && s[k]) 
					{
						u[i]++;
						u[j]++;
						u[k]++;
						tk = 1;
						tk *= cnt(s[i]+u[i]-1,u[i]); 
						if (j != i) tk *= cnt(s[j]+u[j]-1,u[j]);
						if (k != j && k != i) tk *= cnt(s[k]+u[k]-1,u[k]);
						ans += tk;
						u[i]--;
						u[j]--;
						u[k]--;
						
					}
		printf("%I64d\n",ans);
	}
	return 0;
}