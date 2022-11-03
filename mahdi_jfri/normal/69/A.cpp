#include<iostream>
using namespace std;
int main()
{
	int i,sum1=0,sum0=0,sum2=0,b[310];
	cin>>i;
	i*=3;
	for(;i>0;i--)
	{
		cin>>b[i];
		if(i%3==0)
		sum0+=b[i];
		else if(i%3==1)
		sum1+=b[i];
		else
		sum2+=b[i];
	}
	if((sum1!=0)||((sum2!=0)||(sum1!=0)))
	cout<<"NO";
	else if((sum1==0)&&((sum2==0)&&(sum1==0)))
	cout<<"YES";
}