#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int nod(int a, int b)
{
	if(a * b == 0)
	{
		return a + b;
	}
	if(a > b)
	{
		return nod(a % b, b);
	}
	else
	{
		return nod(a, b % a);
	}
}
main(){
    int n, k;
    cin >> n >> k;
    int a, b;
    cin >> a >> b;
    int min2 = 1e18, max2 = 0;
    for(int x = 1; x <= n; x++)
    {
    	int c1 = (a + b) % k;
    	int c2 = (a - b) % k;
    	int c3 = (b - a) % k;
    	int c4 = (-a -b) % k;
    	int nok1 =  n * k / nod(n * k, k * x + c1);
    	int nok2 = n * k / nod(n * k, k * x + c2);
    	int nok3 = n * k / nod(n * k, k * x + c3);
    	int nok4 = n * k / nod(n * k, k * x + c4);
    	int min1 = min(min(nok1, nok2), min(nok3, nok4));
    	int max1 = max(max(nok1, nok2), max(nok3, nok4));
    	if(min1 < min2)
    	{
    		min2 = min1;
		}
		if(max1 > max2)
		{
			max2 = max1;
		}
	}
	cout << min2 << " " << max2;
    return 0;
}