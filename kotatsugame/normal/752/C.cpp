#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<map>
#include<utility>
#include<iomanip>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

int main()
{
	int n;string s;cin>>n>>s;
	int now=0,d=-1,x=0,y=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='L')
		{
			if(d!=1&&d!=2&&d!=5)
			{
				if(d!=4&&d!=6&&d!=-1)
				{
					now++;
					d=-1;
				}
				if(d==0||d==4)d=1;
				else if(d==3||d==6)d=2;
				else if(d==7||d==-1)d=5;
			}
			x--;
		}
		else if(s[i]=='R')
		{
			if(d!=0&&d!=3&&d!=7)
			{
				if(d!=4&&d!=6&&d!=-1)
				{
					now++;
					d=-1;
				}
				if(d==1||d==4)d=0;
				else if(d==2||d==6)d=3;
				else if(d==5||d==-1)d=7;
			}
			x++;
		}
		else if(s[i]=='U')
		{
			if(d!=0&&d!=1&&d!=4)
			{
				if(d!=5&&d!=7&&d!=-1)
				{
					now++;
					d=-1;
				}
				if(d==2||d==5)d=1;
				else if(d==3||d==7)d=0;
				else if(d==6||d==-1)d=4;
			}
			y++;
		}
		else
		{
			if(d!=2&&d!=3&&d!=6)
			{
				if(d!=5&&d!=7&&d!=-1)
				{
					now++;
					d=-1;
				}
				if(d==1||d==5)d=2;
				else if(d==0||d==7)d=3;
				else if(d==4||d==-1)d=6;
			}
			y--;
		}
	}
	cout<<now+1<<endl;
	return 0;
}