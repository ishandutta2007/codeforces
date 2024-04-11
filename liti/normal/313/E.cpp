#include <iostream>
#include <stack>
using namespace  std; 

int main() 
{
	int n,m;
	cin  >> n >> m; 

	int a[m],b[m],r[m];

	int num ; 
	for(int i = 0 ; i < m ; i++ )
	{
		a[i] = 0 ; 
		b[i] = 0; 
		r[i] = 0 ; 
	}
	for(int i = 0 ; i < n ; i++ )
	{
		cin >> num;  
		a[num]++;
	}
	for(int i = 0 ; i < n ; i++ ) 
	{
		 cin >> num ; 
		 b[m-num-1] ++; 
	}

	int i;
	stack<int> s ;

	for(int index = 0 ; index < 2 * m ; index++ ) 
	{
		i = index % m ; 
		for(int j = 0 ; j < a[i] ; j++ ) 
			s.push(i); 
		a[i] = 0;

	
		while ( b[i] != 0 && s.size() != 0 ) 
		{
			int result = ( s.top() + m - i - 1 ) % m;
			r[result]++;
			b[i]--;
			s.pop();
		}
	}

	for(i = m -1 ; i >= 0 ; i-- ) 
	{
		for(int j= 0 ; j < r[i] ; j++ )
			cout << i << ' ' ;
	}
	cout << endl;
}