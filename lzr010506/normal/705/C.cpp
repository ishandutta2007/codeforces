#include <bits/stdc++.h>
#define pb push_back
#define ps push
#define ft front
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int n , q , now , x , ans;
vector <int> v[300000 + 2];
queue <int> qx , qy;
int main()
{
	n = read();
	int T = read();
	while( T -- )
	{
		int sss = read();
		if( sss == 1 ) v[ x = read() ].pb( 1 ) , qx.ps( x ) , qy.ps( v[x].size() - 1 ) , ans++;
		else 
			if( sss == 2 )
			{
				int x = read();
				for( int i = v[x].size() - 1 ; ~i ; i-- )
					if( v[x][i] ) v[x][i] = 0 , ans --;
					else break;
			}
		else if( sss == 3 )
		{
			int t = read();
			while( now < t )
			{
				now ++;
				int X = qx.ft();
				int Y = qy.ft();
				if( v[X][Y] ) v[X][Y] = 0 , ans --;
				qx.pop() , qy.pop();
			}
		}
		printf( "%d\n" , ans );
	}
	return 0;
}