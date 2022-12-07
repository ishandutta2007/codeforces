#include <bits/stdc++.h>
#define new_STE() ( & ( t[ cnt++ ] ) )
using namespace std;
struct STE
{
	int val;
	STE * lf , * rt;
} * root , t[15000000];

int n , cnt;
char orz[10];

void * modify( int x , int y , int deep , STE * cur )
{
	cur -> val += y;
	if( !cur -> lf ) cur -> lf = new_STE();
	if( !cur -> rt ) cur -> rt = new_STE();
	if( deep != -1 ) x & ( 1 << deep ) ? modify( x , y , deep - 1 , cur -> rt ) : modify( x , y , deep - 1 , cur -> lf );
	return cur;
}

int find( int x , int deep , STE * cur )
{
	if( deep == -1 ) return 0;
	if( !cur -> lf ) cur -> lf = new_STE();
	if( !cur -> rt ) cur -> rt = new_STE();
	if( x & ( 1 << deep ) )
		if( cur -> lf -> val ) return find( x , deep - 1 , cur -> lf ) + ( 1 << deep );
		else return find( x , deep - 1 , cur -> rt );
	else
		if( cur -> rt -> val ) return find( x , deep - 1 , cur -> rt ) + ( 1 << deep );
		else return find( x , deep - 1 , cur -> lf );
}
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int main()
{
	root = new_STE();
	modify( 0 , 1 , 31 , root );
	n = read();
	while( n-- )
	{
		scanf( "%s" , orz );
		if( orz[0] == '+' ) modify( read() , 1 , 31 , root );
		else if( orz[0] == '-' ) modify( read() , -1 , 31 , root );
		else printf( "%d\n" , find( read() , 31 , root ) );
	}
	return 0;
}