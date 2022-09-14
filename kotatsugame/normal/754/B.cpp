#include<iostream>
using namespace std;
main()
{
	string s[4];
	for(int i=0;i<4;i++)cin>>s[i];
	bool flag=false;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<2;j++)
		{
			if(s[i].substr(j,3)=="xx."||s[i].substr(j,3)=="x.x"||s[i].substr(j,3)==".xx")
				flag=true;
		}
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<2;j++)
		{
			int co=0,cx=0,cdot=0;
			for(int k=0;k<3;k++)
			{
				if(s[j+k][i]=='o')co++;
				else if(s[j+k][i]=='x')cx++;
				else if(s[j+k][i]=='.')cdot++;
			}
			if(co==0&&cx==2&&cdot==1)flag=true;
		}
	}
	for(int i=0;i<2;i++)
	{
		int co=0,cx=0,cdot=0;
		for(int j=0;j<3;j++)
		{
			if(s[i+j][i+j]=='o')co++;
			else if(s[i+j][i+j]=='x')cx++;
			else if(s[i+j][i+j]=='.')cdot++;
		}
		if(co==0&&cx==2&&cdot==1)flag=true;
	}
	for(int i=0;i<2;i++)
	{
		int co=0,cx=0,cdot=0;
		for(int j=0;j<3;j++)
		{
			if(s[i+j][3-i-j]=='o')co++;
			else if(s[i+j][3-i-j]=='x')cx++;
			else if(s[i+j][3-i-j]=='.')cdot++;
		}
		if(co==0&&cx==2&&cdot==1)flag=true;
	}
	int co=0,cx=0,cdot=0;
	if(s[0][1]=='o')co++;
	else if(s[0][1]=='x')cx++;
	else if(s[0][1]=='.')cdot++;
	if(s[1][2]=='o')co++;
	else if(s[1][2]=='x')cx++;
	else if(s[1][2]=='.')cdot++;
	if(s[2][3]=='o')co++;
	else if(s[2][3]=='x')cx++;
	else if(s[2][3]=='.')cdot++;
	if(co==0&&cx==2&&cdot==1)flag=true;
	co=cx=cdot=0;
	for(int i=0;i<3;i++)
	{
		if(s[1+i][i]=='o')co++;
		else if(s[1+i][i]=='x')cx++;
		else if(s[1+i][i]=='.')cdot++;
	}
	if(co==0&&cx==2&&cdot==1)flag=true;
	co=cx=cdot=0;
	for(int i=0;i<3;i++)
	{
		if(s[i][2-i]=='o')co++;
		else if(s[i][2-i]=='x')cx++;
		else if(s[i][2-i]=='.')cdot++;
	}
	if(co==0&&cx==2&&cdot==1)flag=true;
	co=cx=cdot=0;
	for(int i=0;i<3;i++)
	{
		if(s[1+i][3-i]=='o')co++;
		else if(s[1+i][3-i]=='x')cx++;
		else if(s[1+i][3-i]=='.')cdot++;
	}
	if(co==0&&cx==2&&cdot==1)flag=true;
	cout<<(flag?"YES":"NO")<<endl;
}