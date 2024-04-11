#include <iostream>
using namespace std;

int main()
{

	int n; 
	cin >> n; 

	long long result = 0 ; 

	long long lastNum;
	cin >> lastNum;
	result = lastNum;

	int counter = 1; 
	for(int i =1 ;i < n; i++ )
	{
		long long num;
		cin >> num;

		if ( num > lastNum ) 
		{

			long long a =1 ;
			while ( counter > 1 ) 
			{
				lastNum += 1;
				if ( counter % 2 == 0 ) 
					result++;
				counter /= 2;

				if ( lastNum == num ) 
					break;
			}


			if ( num > lastNum ) 
			{
				counter = 1;
				result += num - lastNum - 1;
				lastNum = num;
				continue;
			}
		}
		
		if ( num == lastNum ) 
		{
			counter++;

		}
//		cout << result << endl;

	}

	while ( counter > 1 ) 
	{
		lastNum += 1;
		if (counter % 2 == 0 ) 
			result++;
		counter /= 2;
	}
	cout << result << endl;
}