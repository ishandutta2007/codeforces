#include <iostream>
#include <map>
using namespace std;

int a[500];
int matrix[500][500];
long long dist[500][500];
long long ans[500];

int main() 
{
	ios::sync_with_stdio(false);
	int n; 
	cin >> n ; 
	for(int i = 0 ; i < n ; i++ )
	{
		for(int j =0 ; j < n ; j++ )
			cin >> matrix[i][j];
	}
	for(int i = n -1 ; i >= 0 ;i-- )
	{
		cin >> a[i];
		a[i]--;
	}

	for(int i =1 ; i< n ; i++ )
	{
		ans[i] = ans[i-1];
		int node = a[i];
		for(int jC = 0 ; jC < i ;jC++ )
		{
			int j = a[jC];
			bool c1= true, c2=true;
			for(int kC = 0 ; kC < i ; kC++ )
			{
				int k = a[kC];
				if ( c1 || matrix[node][k] + dist[k][j] < dist[node][j] ) 
				{
					c1 = false;
					dist[node][j] =  matrix[node][k] + dist[k][j]; 
				}
			
				if ( c2 || matrix[k][node] + dist[j][k] < dist[j][node] ) 
				{
					c2 = false;
					dist[j][node] =  matrix[k][node] + dist[j][k];
				}
					
			}
			ans[i] += dist[j][node] + dist[node][j]; 
			
		}

		for(int jC = 0 ; jC < i ;jC++ ) 
		{
			int j = a[jC];
			for(int kC  =0 ;kC < i ; kC++ )
			{
				int k = a[kC];
				if ( k == j ) 
					continue;

				if ( dist[j][node] + dist[node][k] < dist[j][k] ) 
				{
					ans[i] -= dist[j][k];
					dist[j][k] = dist[j][node] + dist[node][k];
					ans[i] += dist[j][k];
				}
			}
		}
	}

	for(int i = n - 1 ; i >= 0 ; i-- ) 
	{
		cout << ans[i] << ' ' ;
	}
	cout << endl;
}