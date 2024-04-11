#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int num[n];
    vector<int> result;
    result.push_back(0);
    int lossCounter = 0 ; 
    for(int i = 0 ; i < n; i++)
    {
	cin >> num[i];
	if ( num[i] < 0 && lossCounter < 2 )
	{
	    lossCounter++;
	    result[result.size() -1 ]++;
	    continue;   
	}
	if (num[i] >= 0 )
	    result[result.size() - 1]++;
	else
	{
	    result.push_back(1);
	    lossCounter=1;
	}
	
    }

    cout << result.size() << endl;
    
    for(int i =0 ; i < result.size() ; ++i)
	cout << result[i] << ' ';
    cout << endl;

}