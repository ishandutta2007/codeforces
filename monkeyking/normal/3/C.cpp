#include <iostream>
#include <string>
using namespace std;

char b[9];

int win(char c)
{
	for(int i=0;i<3;i++)
	{
		if(b[i*3]==c && b[i*3+1]==c && b[i*3+2]==c) return true;
		if(b[0+i]==c && b[3+i]==c && b[6+i]==c) return true;
	}
	if(b[0]==c && b[4]==c && b[8]==c) return true;
	if(b[2]==c && b[4]==c && b[6]==c) return true;
	return false;
}

int main()
{
	int s1=0,s2=0;
	for(int i=0;i<9;i++)
	{
		cin>>b[i];
		while((b[i]!='X'&&b[i]!='0'&&b[i]!='.'))cin>>b[i];
		if(b[i]=='X') s1++;
		if(b[i]=='0') s2++;
	}
	if((s1-s2)>1 || s2>s1 || win('X')&&win('0'))
	{
		cout<<"illegal"<<endl;
	}
	else if(win('X') && (s1-s2)!=1 || win('0') && s2!=s1)
	{
		cout<<"illegal"<<endl;
	}
	else if((s1+s2)==9 && !win('X'))
	{
		cout<<"draw"<<endl;
	} 
	else if(win('X'))
	{
		cout<<"the first player won"<<endl;
	}
	else if(win('0'))
	{
		cout<<"the second player won"<<endl;
	}
	else if(s1==s2)
	{
		cout<<"first"<<endl;
	}
	else
	{
		cout<<"second"<<endl;
	}
	return 0;
}