#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;
typedef unsigned long long ull;
const int inf = 1000 * 1000 * 1000;
const LL inf64 = LL(inf) * inf;

void qs(int *arr, int l, int r)
{
	int i,j;
	i = l;
	j = r;
	int middle = arr[(i+j)/2];

	do
	{
		while(middle > arr[i]) i++;
		while(middle < arr[j]) j--;

		if(i <= j)
		{
			swap(arr[i],arr[j]);
			i++;
			j--;
		}
	
	}while(i < j);

	if(i < r)qs(arr,i,r);
	if(j > l)qs(arr,l,j);

}
bool solve()
{
	int Mat[33333][3],a,Mass[99999],n,count(0),index;
	bool flag = true;

	cin >> n;

	for(int i(0);i < 33333;i++)
	{
		Mat[i][0] = 8;Mat[i][1] = 8;Mat[i][2] =8;
	}


	for(int i(0);i < n;i++)
		cin >> Mass[i];

	qs(Mass,0,n-1);

	for(int i(0);i < (n/3);i++)
	{
		Mat[i][0] = Mass[i];
	}

	for(int i(n/3);(i < (2*n/3)) && flag;i++)
	{
		index = i;
		do
		{
			if((Mass[index] <= 7) && !(Mass[index]%Mat[count][0]))
			{
				Mat[count][1] = Mass[index];
				Mass[index] = 8;
			}
			index++;
		}while( (index < (2*n/3)) && ( Mat[count][1] % Mat[count][1] ) );

		if((Mat[count][1] == Mat[count][0]) || (Mat[count][1] == 8))
			flag = false;

		count++;
	}
	count = 0;
	for(int i(2*n/3);(i < n) && flag;i++)
	{
		index = i;
		do
		{
			if((Mass[index] <= 7) && !(Mass[index]%Mat[count][1]))
			{
				Mat[count][2] = Mass[index];
				Mass[index] = 8;
			}
			index++;
		}while( (index < n) && ( Mat[count][2] % Mat[count][1] ) );

		if((Mat[count][2] == Mat[count][1]) || (Mat[count][2] == 8))
			flag = false;

		count++;
	}

	if(flag)
	{
		for(int i(0);i < (n/3);i++)
			cout << Mat[i][0] << " " << Mat[i][1] << " " << Mat[i][2] << endl;
	}else
		cout << "-1";


	return true;
}

int main(int argc,char** argv)
{
	solve();

	return 0;
}