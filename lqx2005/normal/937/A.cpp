#include<bits/stdc++.h>
using namespace std;
int bucket[1000],n,x;
int main() 
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		bucket[x]++;
	}
	int step=0;
	for(int i=1;i<=600;i++)
	{
		if(bucket[i]>0) step++;
	}
	cout<<step<<endl;
    return 0;
}