#include<bits/stdc++.h>
using namespace std;
int a1,b1,a2,b2,a3,b3,a4,b4;
bool can1[2][2],can2[2][2];
int main()
{
	cin>>a1>>b1>>a2>>b2>>a3>>b3>>a4>>b4;
	//a1 b2 a3 b4 
	if (a1>b4 && b2>a3) can1[0][0]=1;
	if (b4>a1 && a3>b2) can2[0][0]=1;
	//a2 b1 a3 b4
	if (a2>b4 && b1>a3) can1[1][0]=1;
	if (b4>a2 && a3>b1) can2[1][0]=1;
	//a1 b2 a4 b3
	if (a1>b3 && b2>a4) can1[0][1]=1;
	if (b3>a1 && a4>b2) can2[0][1]=1;
	//a2 b1 a4 b3
	if (a2>b3 && b1>a4) can1[1][1]=1;
	if (b3>a2 && a4>b1) can2[1][1]=1;
	if ((can1[0][0] && can1[0][1]) || (can1[1][0] && can1[1][1]))
	{
		cout<<"Team 1"<<endl;
		return 0;
	}
	if ((can2[0][1] || can2[0][0]) && (can2[1][0] || can2[1][1])) 
	{
		cout<<"Team 2"<<endl;
		return 0;
	}
	cout<<"Draw"<<endl;
	return 0;
}