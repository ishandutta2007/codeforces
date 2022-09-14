#include<iostream>
using namespace std;

int main()
{
	int n,k,i;
	string s;
	int ans[100]={0};
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>s;
		ans[s.length()-1]++;
	}
	cin>>s;
	int min=0,max;
	for(i=0;i<s.length()-1;i++)min+=ans[i];
	max=min;
	min+=min/k*5+1;
	max+=ans[s.length()-1];
	max+=(max-1)/k*5;
	cout<<min<<" "<<max<<endl;
	return 0;
}