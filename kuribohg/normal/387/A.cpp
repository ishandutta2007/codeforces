#include<iostream>
#include<string>
using namespace std;
string time1str,time2str;
int time1,time2,time3,hour1,minute1;
int main()
{
	cin>>time1str>>time2str;
	time1=((time1str[0]-'0')*10+time1str[1]-'0')*60+(time1str[3]-'0')*10+time1str[4]-'0';
	time2=((time2str[0]-'0')*10+time2str[1]-'0')*60+(time2str[3]-'0')*10+time2str[4]-'0';
	time3=time1-time2;
	if(time3<0) time3+=24*60;
	hour1=time3/60;
	minute1=time3%60;
	if(hour1<10) cout<<"0"<<hour1;
	else cout<<hour1;
	cout<<":";
	if(minute1<10) cout<<"0"<<minute1<<endl;
	else cout<<minute1<<endl;
	return 0;
}