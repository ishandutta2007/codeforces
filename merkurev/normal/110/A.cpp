#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

int main(){
	//freopen("input.txt","rt",stdin);
	//freopen("output.txt","wt",stdout);
	long long n;
	int k=0;
	cin>>n;
	while (n)
	{
		if (n%10==4 || n%10==7) k++;
		n/=10;
	}
	if (!k) 
	{
		cout<<"NO";
		return 0;
	}
	while (k)
	{
		if (k%10!=4 && k%10!=7)
		{
			cout<<"NO";
			return 0;
		}
		k/=10;
	}
	cout<<"YES";
	return 0;
}