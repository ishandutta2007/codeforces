#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	long m;
	cin >> m;
	vector<long> q(m);
	for(long i = 0; i < m; i++)
		cin >> q[i];
	long n;
	cin >> n;
	vector<long> a(n);
	
	long price  = 0;
	for(long i = 0 ;i < n;i++){
		cin >> a[i];
		price += a[i];
	}
	sort ( a.begin() , a.begin() + n);
	sort ( q.begin() , q.begin() + m );
	long index = n - 1;
		for(int i = 0; i < m ;i++){
//			cout << q[i] << endl;
			if ( q[i] < index + 1 )
			{
				index = index - q[i];
				if ( index == -1 ) 
					break;
				price -=  a[index];
				index--;
				if ( index == -1 )
					break;
				price -=  a[index];
				index--;
				i = i - 1;
			}		
			if ( index < 0 )
				break;
		}
		cout << price << endl;
}