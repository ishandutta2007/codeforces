#include<iostream>
#include<cmath>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
vector <int> vec;
bool can[1005];
void PrimeDecomposition(int k)
{
//cout<<k<<"=";
if(k<2) return;
//cout<<""<<endl;
else if(k==2)
	vec.push_back(2);
else
{

for(int i=2;i<=sqrt(k);i++)
{
while(k!=i)//whilei
{
if(k%i==0)
{
	vec.push_back(i);
	//cout<<i<<"*";
	k=k/i;
}
else
break;
}
}
vec.push_back(k);
//cout<<k<<endl;
}
}
//
/*void Analyse(int n)  
{  
    //  
    cout<<n<<" = ";  
  
    //n2  
    //2  
    if(n == 2)  
    {  
        cout<<n<<endl;  
    }  
    //n2  
    else if(n < 2)  
    {  
        cout<<""<<endl;  
    }  
    else  
    {  
        //n>=k,nkk  
        for(int i = 2;i <= sqrt(static_cast<double>(n));i++)  
        {  
            if(n % i == 0)  //whilei--
            {  
                n = n/i;  
                cout<<i<<"*";  
                //  
                i--;  
            }  
        }  
        cout<<n<<endl;  
    }  
}  */
int main()
{
	int n;
	cin>>n;
	int a,b;
	int len;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
//		cout<<len<<endl;
		if(i)
		{
			for(int i=0;i<len;i++)
			{
				if(a%vec[i] && b%vec[i]) can[i]=true;
//				if() can[i]=true;
			}
		}
		else
		{
			PrimeDecomposition(a);
			PrimeDecomposition(b);
			sort(vec.begin(),vec.end());
			len=unique(vec.begin(),vec.end())-vec.begin();
		}
	}
	for(int i=0;i<len;i++)
	{
//		cout<<vec[i]<<' ';
		if(can[i]) continue;
		cout<<vec[i]<<endl;
		return 0;
	}
	cout<<-1<<endl;
//	for(int i=0;i<vec.size();i++)
//	{
//		cout<<vec[i]<<' ';
//	}
//	PrimeDecomposition(n);
	return 0;
}