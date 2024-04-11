#include<iostream>
using namespace std;
bool isr(int y){return y%4?false:y%100?true:y%400?false:true;}
int y;
main()
{
	cin>>y;
	bool f=isr(y);
	int d=0;
	do{
		d+=isr(y)?366:365;
		y++;
	}while(d%7||f!=isr(y));
	cout<<y<<endl;
}