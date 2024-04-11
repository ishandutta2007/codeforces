#include<bits/stdc++.h>
#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define mpr make_pair
#define x(v) (v).first
#define y(v) (v).second
#define siz(v) (int)(v).size()
#define pb push_back
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef double db;
const int N = 1e5 + 10;
int t, n;
int a[N], sg[100][100][2][2];
int main()
{
//	sg[0][0][1][0] = 1;
//	rep(i, 0, 10)
//	{
//		rep(j, 0, 10)
//		{
//			if(!i && !j) continue;
//			rep(k, 0, 1)
//			{
//				rep(l, 0, 1)
//				{
//					if((k + l + i) % 2 == 0) continue;
//					int flag = 0;
//					if(i > 0)	flag |= (sg[i - 1][j][l][k ^ 1] == 0);
//					if(j > 0) flag |= (sg[i][j - 1][l][k] == 0);
//					sg[i][j][k][l] = flag;
//					if(k == 0 && l == 0) cout << i <<" "<< j <<" "<< sg[i][j][k][l] << endl;					
//				}
//			} 
//		}
//	}
	scanf("%d", &t);
	rep(amo, 1, t)
	{
		scanf("%d", &n);
		int sum = 0;
		rep(i, 1, n) scanf("%d", &a[i]), sum ^= a[i];
		if(sum == 0) 
		{
			printf("DRAW\n");
			continue;
		}
		int pos = -1;
		per(i, 30, 0)
		{
			if(sum & (1 << i))
			{
				pos = i;
				break;
			}
		}
		int cnt = (n + 1) / 2, tnc = 0;
		rep(i, 1, n) if(a[i] & (1 << pos)) tnc++;
		int oth = n - tnc;
		if(tnc % 4 == 1) printf("WIN\n");
		else
		{
			if(oth & 1) printf("WIN\n");
			else printf("LOSE\n");			
		}	
	}
	return 0;
}