#include <bits/stdc++.h>
using namespace std;

int cal(int b)
{
	return ((b)*(b+1))/2;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int x,i;
		cin>>x;
		for(i=1;i<=1e4;i++)
			if(cal(i) >= x)
				break;
		if(cal(i) != x+1)
			cout<<i<<endl;
		else
			cout<<i+1<<endl;
	}
	return 0;
}