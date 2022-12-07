#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define new_Node() ( & t[ cnt++ ] )

using namespace std;

int n , cnt;
char opt[5] , s[20];

struct Node
{
	int value;
	Node * ch[2];
} t[5000000] , * root;

void insert( int pos , int v , Node * cur )
{
	if( s[ pos ] == 0 )
	{
		cur -> value += v;
		return;
	}
	if( !cur -> ch[ s[ pos ] - '0' ] ) cur -> ch[ s[ pos ] - '0' ] = new_Node();
	insert( pos + 1 , v , cur -> ch[ s[ pos ] - '0' ] );
}

int find( int pos , Node * cur )
{
	if( !cur -> ch[ s[ pos ] - '0' ] ) cur -> ch[ s[ pos ] - '0' ] = new_Node();
	if( s[ pos ] == 0 )	return cur -> value;
	return find( pos + 1 , cur -> ch[ s[ pos ] - '0' ] );
}

int main()
{
	cin >> n;
	root = new_Node();
	while( n-- )
	{
		memset( s , 0 , sizeof( s ) );
		scanf( "%s %s" , opt , s );
		reverse( s , s + strlen( s ) );
		for( register int i = 0 ; i < 18 ; i++ )
			if( s[i] & 1 )
				s[i] = '1';
			else s[i] = '0';
		if( opt[0] == '+' ) insert( 0 , 1 , root );
		else if( opt[0] == '-' ) insert( 0 , -1 , root );
		else printf( "%d\n" , find( 0 , root ) );
	}
	return 0;
}